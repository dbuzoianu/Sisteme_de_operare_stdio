#include <sys/types.h>	/* open */
#include <sys/stat.h>	/* open */
#include <fcntl.h>	/* O_RDWR, O_CREAT, O_TRUNC, O_WRONLY */
#include <unistd.h>	/* close */
 
#include "so_stdio.h"

SO_FILE *so_fopen(const char *pathname, const char *mode) {

	SO_FILE my_SO;
	my_SO = calloc(sizeof(SO_FILE));

	if (strcmp(mode, 'r')){
		my_SO->fd = open(pathname, O_RDONLY);	
	}

	if (strcmp(mode, 'r+')){
		my_SO->fd = open(pathname, O_RDWR);
	}

	if (strcmp(mode, 'w')){
		my_SO->fd = open(pathname, O_WRONLY | O_TRUNC | O_CREAT, 0644);	
	}

	if (strcmp(mode, 'w+')){
		my_SO->fd = open(pathname, O_RDWR | O_TRUNC | O_CREAT, 0644);
	}

	if (strcmp(mode, 'a')){
		my_SO->fd = open(pathname, O_WRONLY | O_CREAT | O_APPEND, 0644);
	}

	if (strcmp(mode, 'a+')){
		my_SO->fd = open(pathname, O_RDWR | O_CREAT | O_APPEND, 0644);
	}
}

int so_fclose(SO_FILE *stream) {
	return close(stream->fd);
}

int so_fgetc(SO_FILE *stream) {
	unsigned char *buf;
	int aux = read(int stream->fd, buf, sizeof(unsigned char));
	return aux < 0 ? SO_EOF : (int) buf;
}

int so_fputc(int c, SO_FILE *stream) {
	unsigned char *buf;
	buf = (unsigned char)c;
	int aux = write(stream->fd, buf, sizeof(unsigned char));
	return aux < 0 ? SO_EOF : c;
}

size_t so_fread(void *ptr, size_t size, size_t nmemb, SO_FILE *stream) {
	unsigned char *buf;
}