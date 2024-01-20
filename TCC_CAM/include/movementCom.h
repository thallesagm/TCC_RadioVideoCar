#ifndef MOVEMENT_COM_INCLUDED
#define MOVEMENT_COM_INCLUDED

void serialReceiver (void * parameter);
void handlesCommand (char * command);
int handlesHTTPCommand(char * variable);

#endif