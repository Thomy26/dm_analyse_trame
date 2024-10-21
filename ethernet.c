#include <stdio.h>
#include <string.h>
#include "common.h"
#include "ethernet.h"

// Analyser entete Ethernet
void analyserEthernet(char *trame, Ethernet *ethernet) 
{    
    memcpy(&ethernet->destination, trame, 6);
    memcpy(&ethernet->source, &trame[6], 6);
    ethernet->longueur = MAKE_SHORT(trame[12], trame[13]);
}

// Afficher une adresse Ethernet / MAC
void afficherAdresseEthernet(char *adresse)
{
         // Affichage de l'adresse MAC en format xx:xx:xx:xx:xx:xx
    printf("%02x:%02x:%02x:%02x:%02x:%02x",
           (unsigned char)adresse[0],
           (unsigned char)adresse[1],
           (unsigned char)adresse[2],
           (unsigned char)adresse[3],
           (unsigned char)adresse[4],
           (unsigned char)adresse[5]);
}

// Afficher entete Ethernet
void afficherEthernet(Ethernet ethernet)
{
    printf("Ethernet:\n");
    printf("    destination: ");
    afficherAdresseEthernet(ethernet.destination);
    printf("\n");
    printf("    source: ");
    afficherAdresseEthernet(ethernet.source);
    printf("\n");
    printf("    longueur: %d\n", ethernet.longueur);
}
