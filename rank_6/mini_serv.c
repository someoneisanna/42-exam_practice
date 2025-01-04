#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

void error(char *msg, int exit_code)
{
	for (int i = 0; msg[i] != '\0'; i++)
		write(2, &msg[i], 1);
	exit (exit_code);
}

int main(int ac, char **av)
{
	// Check if there is only one argument
	
	if (ac != 2)
		error("Wrong number of arguments\n", 1);

	// Create a socket

	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error("Fatal error\n", 1);

	// Assign IP and Port
	
	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(av[1]));

	// Bind socket to IP

	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		error("Fatal error\n", 1);
	if (listen(sockfd, 10) != 0)
		error("Fatal error\n", 1);

	// Use select
	fd_set allfds, rfds, wfds;

	FD_ZERO(&allfds);
	FD_SET(sockfd, &allfds);
	int max_fd = sockfd;

	struct sockaddr_in cli;
	socklen_t len = sizeof(cli);

	while (1)
	{
		rfds = wfds = allfds;
		int select_var = select(max_fd + 1, &rfds, &wfds, 0, 0);
		if (select_var < 0)
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
					printf("Connection accepted from client.\n");
					FD_SET(client_socket, &allfds);
					if (client_socket > max_fd)
						max_fd = client_socket;
				}
			}
		}
	}
}
