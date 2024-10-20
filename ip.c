#include <stdio.h>
#include "common.h"
#include "ip.h"

// Analyser entete IP
    void analyserIP(char *trame, IP *ip) 
{
    if (trame == NULL || ip == NULL) {
            error_exit("Fonction analyserIP() non implémentée");
    }

    // Remplir les champs de la structure IP
    ip->version = (trame[0] >> 4) & 0x0F; // Les 4 premiers bits
    ip->IHL = trame[0] & 0x0F; // Les 4 derniers bits
    ip->typeOfService = trame[1];
    ip->totalLength = (trame[2] << 8) | trame[3]; // Big-endian
    ip->identification = (trame[4] << 8) | trame[5]; // Big-endian
    ip->flags = (trame[6] >> 5) & 0x07; // Les 3 premiers bits
    ip->fragmentOffset = ((trame[6] & 0x1F) << 8) | trame[7]; // Big-endian
    ip->timeToLive = trame[8];
    ip->protocol = trame[9];
    ip->HeaderChecksum = (trame[10] << 8) | trame[11]; // Big-endian

    // Convertir les adresses IP de la représentation binaire à un entier
    ip->sourceIP = (trame[12] << 24) | (trame[13] << 16) | (trame[14] << 8) | trame[15];
    ip->destinationIP = (trame[16] << 24) | (trame[17] << 16) | (trame[18] << 8) | trame[19];
}

// Afficher une adresse IP
void afficherIPAddress(unsigned int address)
    {
    if (adresse == NULL) {
        printf("Adresse Ethernet non valide\n");
        return;
    }

    printf("Adresse Ethernet: ");
    for (int i = 0; i < 6; i++) {
        // Afficher chaque octet en hexadécimal
        printf("%02X", adresse[i]);
        // Ajouter un ':' après chaque octet sauf le dernier
        if (i < 5) {
            printf(":");
        }
    }
    printf("\n");
}

// Afficher entete IP
void afficherIP(IP ip)
{
    printf("IP:\n");
    printf("    version: %d\n", ip.version);
    printf("    IHL: %d\n", ip.IHL);
    printf("    typeOfService: %d\n", ip.typeOfService);
    printf("    totalLength: %d\n", ip.totalLength);
    printf("    identification: %d\n", ip.identification);
    printf("    flags: %d\n", ip.flags);
    printf("    fragmentOffset: %d\n", ip.fragmentOffset);
    printf("    timeToLive: %d\n", ip.timeToLive);
    printf("    protocol: %d\n", ip.protocol);
    printf("    HeaderChecksum: %d\n", ip.HeaderChecksum);
    printf("    sourceIP: ");
    afficherIPAddress(ip.sourceIP);
    printf("\n    destinationIP: ");
    afficherIPAddress(ip.destinationIP);
    printf("\n");
}