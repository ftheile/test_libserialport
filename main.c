#include <stdio.h>
#include <libserialport.h>

struct client {
	struct sp_port** port_list;
};

static struct client theApp;

int main(int argc, char* argv[])
{
	enum sp_return ret = sp_list_ports(&theApp.port_list);
	if (ret == SP_OK) {
		struct sp_port** port_iter = theApp.port_list;
		while (*port_iter) {
			const char* name = sp_get_port_name(*port_iter);
			if (name) {
				printf("%s\n", name);
			}
			port_iter++;
		}
		sp_free_port_list(theApp.port_list);
	} else {
		printf("sp_list_ports(): %d\n", ret);
	}
	return 0;
}
