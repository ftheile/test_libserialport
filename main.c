#include <stdio.h>
#include <libserialport.h>

struct client {
	struct sp_port** port_list;
};

static struct client theApp;

int main(int argc, char* argv[])
{
	int ret = 0;
	enum sp_return sp_ret = sp_list_ports(&theApp.port_list);
	if (sp_ret == SP_OK) {
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
		printf("sp_list_ports(): %d\n", sp_ret);
		ret = -1;
	}
	return ret;
}
