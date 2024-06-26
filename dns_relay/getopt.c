#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

void show_help()
{
    printf("Usage: getopt [options]\n"
           "Options:\n"
           "  -?, --help                  Show help information\n"
           "  -f, --file <filename>       Specify a file name\n"
           "  -s, --server <address>      Specify the server IP address\n"
           "  -d                          Enable level 1 debug output\n"
           "  -dd                         Enable level 2 debug output\n"
           "  -p, --port <number>         Set the port number\n"
           "  -c, --cache <size>          Set cache size\n"
           "  -bs <address>               Specify backup DNS server IP\n"
           "  -b, --block <domain>...     Specify domain names to block\n");
}

int main(int argc, char *argv[])
{
    int opt;
    int debug_level = 0;

    struct option long_opts[] = {
        {"help", no_argument, NULL, '?'},
        {"file", required_argument, NULL, 'f'},
        {"server", required_argument, NULL, 's'},
        {"port", required_argument, NULL, 'p'},
        {"cache", required_argument, NULL, 'c'},
        {"block", required_argument, NULL, 'b'},
        {NULL, 0, NULL, 0}};

    while ((opt = getopt_long(argc, argv, "?f:s:dp:c:b:bs:", long_opts, NULL)) != -1)
    {
        switch (opt)
        {
        case '?':
            show_help();
            break;
        case 'f':
            printf("File name set to %s\n", optarg);
            break;
        case 's':
            printf("Server IP set to %s\n", optarg);
            break;
        case 'd':
            if (debug_level == 0)
            {
                debug_level = 1;
                printf("Level 1 debug output enabled\n");
            }
            else if (debug_level == 1 && strcmp(argv[optind - 1], "-dd") == 0)
            {
                debug_level = 2;
                printf("Level 2 debug output enabled\n");
            }
            break;
        case 'p':
            printf("Port set to %s\n", optarg);
            break;
        case 'c':
            printf("Cache size set to %s\n", optarg);
            break;
        case 'b':
            printf("Blocking domain: %s\n", optarg);
            while (optind < argc && argv[optind][0] != '-')
            {
                printf("Also blocking domain: %s\n", argv[optind]);
                optind++;
            }
            break;
        case 'bs':
            printf("Backup DNS server set to %s\n", optarg);
            break;
        default:
            printf("Unknown option: %c\n", opt);
            printf("getopt -help or -? for help\n");
            exit(EXIT_FAILURE);
        }
    }

    if (argc == 1)
    {
        printf("No arguments provided.\ngetopt -help or -? for help\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
