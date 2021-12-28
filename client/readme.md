1. Generate the service and data binding interface for the client side with:
    soapcpp2 -c -r -CL calc.h
2. To build the example client application:
    c++ -o calcclient calcclient.cpp soapC.cpp soapClient.cpp -l gsoap++