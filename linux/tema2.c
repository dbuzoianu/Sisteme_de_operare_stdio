#include <sys/types.h>	/* open */
#include <sys/stat.h>	/* open */
#include <fcntl.h>	/* O_RDWR, O_CREAT, O_TRUNC, O_WRONLY */
#include <unistd.h>	/* close */
#include <sys/file.h>
#include <string.h>


#include "so_stdio.h"

#define BUFFSIZE 4096

SO_FILE *so_fopen(const char *pathname, const char *mode) {

	SO_FILE *my_SO = calloc(1, sizeof(SO_FILE));

	if (my_SO == NULL) {
		return NULL;
	}

	if (strcmp(mode, "r") == 0){
		my_SO->fd = open(pathname, O_RDONLY);	
	} else if (strcmp(mode, "r+") == 0){
		my_SO->fd = open(pathname, O_RDWR);
	} else if (strcmp(mode, "w") == 0){
		my_SO->fd = open(pathname, O_WRONLY | O_CREAT | O_TRUNC, 0644);	
	} else if (strcmp(mode, "w+") == 0){
		my_SO->fd = open(pathname, O_RDWR | O_CREAT | O_TRUNC, 0644);
	} else if (strcmp(mode, "a") == 0){
		my_SO->fd = open(pathname, O_WRONLY | O_CREAT | O_APPEND, 0644);
	} else if (strcmp(mode, "a+") == 0){
		my_SO->fd = open(pathname, O_RDWR | O_CREAT | O_APPEND, 0644);
	} else {
		free(my_SO);
		return NULL;
	}

	if (my_SO->fd < 0) {
		free(my_SO);
		return NULL;
	}

	return my_SO;
}

int so_fclose(SO_FILE *stream) {
	if(close(stream->fd) < 0) {
		free(stream);
		return SO_EOF;
	}

	free(stream);
	return 0;
}

int so_fgetc(SO_FILE *stream) {
	unsigned char c_aux;

	if(stream->buff_pointer == 0) {
		// printf("Aici\n");
		stream->caract_citite = read(stream->fd, stream->buff, BUFFSIZE);

		if (stream->caract_citite <= 0) {
			return SO_EOF;
		}
	} 

	c_aux = stream->buff[stream->buff_pointer];
	stream->buff_pointer++;

	if(stream->buff_pointer == stream->caract_citite) {
		stream->buff_pointer = 0;
	}

	// printf("\n%c\n", c_aux);
	return (int)c_aux;
}

int so_fputc(int c, SO_FILE *stream) {
	unsigned char buf[10];
	buf[0] = (unsigned char)c;
	int aux = write(stream->fd, buf, sizeof(unsigned char));
	return aux < 0 ? SO_EOF : c;
}

// size_t so_fread(void *ptr, size_t size, size_t nmemb, SO_FILE *stream) {
// 	unsigned char *buf;
// }
size_t so_fread(void *ptr, size_t size, size_t nmemb, SO_FILE *stream) {
	return NULL;
}
size_t so_fwrite(const void *ptr, size_t size, size_t nmemb, SO_FILE *stream){
	return NULL;
}
int so_fseek(SO_FILE *stream, long offset, int whence){
	return NULL;
}
long so_ftell(SO_FILE *stream){
	return NULL;
}
int so_fflush(SO_FILE *stream){
	return NULL;
}
int so_fileno(SO_FILE *stream){
	return NULL;
}
int so_feof(SO_FILE *stream){
	return NULL;
}
int so_ferror(SO_FILE *stream){
	return NULL;
}
SO_FILE *so_popen(const char *command, const char *type){
	return NULL;
}
int so_pclose(SO_FILE *stream){
	return NULL;
}