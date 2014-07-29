#include "socket.h"

using namespace network;

char buffer[5242880];
timeval t;


/*!
 *
 */
int net::sock(std::string file, int portno, std::string host )
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;


    //creer la socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    //std::cout<<"FileDesc Socket : "<<sockfd<<std::endl;
    if (sockfd < 0) return 1;

    //char* opt="1";

    //setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, &opt, sizeof(opt));

    //tester le nom de machine passé en paramétre
    server = gethostbyname(host.c_str());
    if (server == NULL) return 2;

    //mettre à zero la structure sockaddr_in
    bzero((char *) &serv_addr, sizeof(serv_addr));
    //type de famille réseau
    serv_addr.sin_family = AF_INET;
   //copier ip vers sockaddr_in
    bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
    //fixer le port
    serv_addr.sin_port = htons(portno);

    //connecter la socket....
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) return 3;
    //std::cout<<"Connected to socket serveur..."<<std::endl;

    //lire le contenu du fichier...
    bzero(buffer,5242880);

    long nbr=read_file(file);

    //ecrire sur la socket
    n = write(sockfd,buffer,nbr);

    gettimeofday(&t,NULL);
    std::cout<<t.tv_usec<<": "<<file<<" # write :"<<n<<" bytes on socket => fd "<<sockfd<<" ip "<<server->h_name<<" port "<<portno<<std::endl;
    if (n < 0) return 4;

 //fermer la socket
    close(sockfd);
//tout est OK
    return 0;
}

/*!
 *
 */
net::net(){
	//do nothing...
}

long net::read_file(std::string fichier){
FILE* pfile;
char c;
int i=0;

if (mllp){buffer[i]=0x0B;i++;}


pfile=fopen(fichier.c_str(),"r");

if (pfile!=NULL){
	do {
	c=fgetc(pfile);
	buffer[i]=c;
	i++;
	} while (c!=EOF);

if (mllp){buffer[i]=0x1C;}

	fclose(pfile);
}

return i-1;
}


void net::setMLLP(bool mllp){
	net::mllp=mllp;
}

/*!
 *
 */
net::~net(){
	//do nothing...
}
