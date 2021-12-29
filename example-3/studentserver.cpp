#include "soapH.h"
#include "ns.nsmap"

int main(int argc, char **argv)
{
  SOAP_SOCKET m, s; /* sockets */
  struct soap soap;
  soap_init(&soap);
  if (argc < 2)
    soap_serve(&soap);	/* serve as CGI application */
  else
  {
    m = soap_bind(&soap, NULL, atoi(argv[1]), 1);
    if (!soap_valid_socket(m))
    {
      soap_print_fault(&soap, stderr);
      exit(1);
    }
    fprintf(stderr, "Socket connection successful: master socket = %d\n", m);
    for ( ; ; )
    {
      s = soap_accept(&soap);
      fprintf(stderr, "Socket connection successful: slave socket = %d\n", s);
      if (!soap_valid_socket(s))
      {
        soap_print_fault(&soap, stderr);
        exit(1);
      } 
      soap_serve(&soap);
      soap_end(&soap);
    }
  }
  return 0;
}

int ns__hello(struct soap *soap, Student s, Student& greeting)
{
  greeting.name = "Name : "+s.name;
  greeting.subject="Subject : "+s.subject;
  return SOAP_OK;
}