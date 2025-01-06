#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

int		sockfd, max_fd, clients[5000], client_id;
fd_set	allfds, rfds, wfds;

void error(char *msg, int exit_code)
{
	if (sockfd > 2)
		close(sockfd);
	write(2, msg, strlen(msg));
	exit (exit_code);
}

void broadcast_message(char *msg, int client_socket, char *buffer)
{
	char str[500000];
	bzero(str, 500000);
	if (buffer)
		sprintf(str, msg, clients[client_socket], buffer);
	else
		sprintf(str, msg, clients[client_socket]);
	for (int fd = 0; fd <= max_fd; fd++)
	{
		if (FD_ISSET(fd, &wfds) && fd != client_socket)
		{
			if (send(fd, str, strlen(str), 0) < 0)
				error("Fatal error\n", 1);
		}
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		error("Wrong number of arguments\n", 1);
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error("Fatal error\n", 1);
	
	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(av[1]));
	
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		error("Fatal error\n", 1);
	if (listen(sockfd, 10) != 0)
		error("Fatal error\n", 1);
	
	FD_ZERO(&allfds);
	FD_SET(sockfd, &allfds);
	max_fd = sockfd;
	client_id = 0;
	
	struct sockaddr_in cli;
	socklen_t len = sizeof(cli);
	
	while (1)
	{
		rfds = wfds = allfds;
		if (select(max_fd + 1, &rfds, &wfds, 0, 0) < 0)
			continue;
		for (int fd = 0; fd <= max_fd; fd++)
		{
			if (FD_ISSET(fd, &rfds))
			{
				if (fd == sockfd)
				{
					int client_socket = accept(sockfd, (struct sockaddr *)&cli, &len);
					if (client_socket < 0)
						error("Fatal error\n", 1);
					FD_SET(client_socket, &allfds);
					if (client_socket > max_fd)
						max_fd = client_socket;
					clients[client_socket] = client_id++;
					broadcast_message("server: client %d just arrived\n", client_socket, NULL);
				}
				else
				{
					char buffer[500000];
					bzero(buffer, 500000);
					int bytes_received = 1;
					while(bytes_received == 1 && buffer[strlen(buffer) - 1] != '\n')
						bytes_received = recv(fd, buffer + strlen(buffer), 1, 0);
					if (bytes_received <= 0)
					{
						broadcast_message("server: client %d just left\n", fd, NULL);
						FD_CLR(fd, &allfds);
						close(fd);
					}
					else
						broadcast_message("client %d: %s", fd, buffer);
				}
			}
		}
	}
}