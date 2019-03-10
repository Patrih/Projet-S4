#include "adc.h"
#include "lcd.h"
#include <stdio.h>
#include <stdint.h>
#include "uart.h"

// CONSTANTE -------------------------------------------------------------------
int PERIOD_SEND = 100;
int CLK = 100;
// ------------------------------------------------------------------------------





// VARIABLE GLOBAL -------------------------------------------------------------
char G_error = 0;
int G_flag_evo = 0;
int G_flag_spasm = 0;
// -----------------------------------------------------------------------------





// FONCTION --------------------------------------------------------------------

/* Entr�: Le signal analogique du EMG
 * Sortie: Le signal transform� (maintenant digital) de l'EMG
 * Fonction: Lire le signal de l'emg et le transofmrer en signal digital grace
 *           � l'ADC.
 */
int Read (int analog_emg)
{
    int digital_emg = 0;
    
    return digital_emg;
}

/* Entr�: Le signal digital de l'emg
 * Sortie: Le signal digital redresser pour n'avoir que des positifs
 * Fonction: Redresser le signal digital pour ne pas avoir de n�gatif. On
 *           regarde l'intensit� donc le n�gatif ou positif ne compte pas.
 */
int Rectifier (int digital_emg)
{
    int emg_rect = 0;
    
    return emg_rect;
}

/* Entr�: 1- La valeur redresser du emg. 2- Period de temps avant d'envoyer les 
 *        donn� du buffer (1 seconde "worth" de donn�es)
 * Sortie: La moyenne de tout les donn�es dans le buffer
 * Fonction: Prendre les donn�es redress�, les placer dans un buffer et envoyer 
 *           le buffer dans une fonction de calcule de moyenne apres X nombre de donn�e recu
 */
int Intensity_Value (int emg_rect, int send_period)
{
    int intensity = 0;
    
    if (G_flag_evo == 1)
    {
        Save_Evo(intensity);
    }
    
    if (G_flag_spasm == 1)
    {
        Save_Spasm(intensity);
    }
    
    Display_Intesity_LCD(intensity, CLK, PERIOD_SEND);
    
    return intensity;
}

/* Entr�: L'intensit� moyenne calcul� sur 1 seconde
 * Sortie: Rien
 * Fonction: Sauvegarder dans la flash les valeurs que l'utilisateur veut 
 *           sauvegarder
 */
void Save_Evo (int intensity)
{
    
}

/* Entr�: L'intensit� moyenne calcul� sur 1 seconde
 * Sortie: Rien
 * Fonction: Sauvegarder dans la flash les valeurs de la crise de l'utilisateur
 */
void Save_Spasm (int intensity)
{
    
}

/* Entr�: 1- Intensit� moyenne calcul� sur 1 seconde. 2- Le clk pour une 
 *        synchronisation de l'affichage. 3- Le nombre de donn�e a afficher 
 *        repr�sentant 1 seconde.
 * Sortie: Rien
 * Fonction: Afficher la moyenne de 1 seconde de donn�es sur le LCD
 */
void Display_Intesity_LCD (int intensity, int clk, int period_send)
{
    
}

/* Entr�: Le signal redresser de l'emg
 * Sortie: Rien
 * Fonction: Envoie des valeurs de moyenne a la carte zybo
 */
void Send_Value_Spasm (int emg_rect)
{
    
}

/* Entr�: Reception des donn�es envoyer par la zybo
 * Sortie: La valeur du flag qui dit si une crise a lieu
 * Fonction: Lecture des donn�es envoyer par la carte zybo et si une crise 
 *           d'�pilepsie est detecter, on retourne un 1. Sinon, on retourne un 0.
 */
int Receive_Spasm (int comm_zybo)
{
    int flag_spasm = 0;
    
    return flag_spasm;
}

/* Entr�: 1- Intensit� moyenne sur 1 seconde du signal de l'emg. 2- Les valeurs 
 *        du spasm ? 3- Valeur du flag qui indique si une crise a lieux
 * Sortie: Donn�e envoyer � l'ordinateur par UART
 * Fonction: Envoyer, � chaque 2 seconde, les valeurs d'intensit� calcul� et 
 *           d'afficher le message de crise si une crise a lieux
 */
int Interruption_2sec (int intensity, int spasm, int flag_spasm)
{
    int comm_UART = 0;
    
    return comm_UART;
}

/* Entr�: Rien
 * Sortie: Flag si l'utilisateur veut enregistr� ses donn�es
 * Fonction: Si le bouton d'enregistrement est peser, les donn�es sont 
 *           enregistr� sur 3 seconde
 */
int Interruption_10ms ()
{
    int flag_evo = 0;
    
    return flag_evo;
}

// -----------------------------------------------------------------------------





// MAIN ------------------------------------------------------------------------	
int main()
{
/* 1- Setup ADC et autre
 * 2- while(1)
 * 3- read adc
 * 4- redressage signal
 * 5- moyenne de l'intensit�
 * 6- si bouton appuyer, sauvegarde de l'evolution en memoire flash
 * 7- display de l'intensit� sur le LCD
 * 8- Envoie des valeurs a la zybo pour decider si cest une crise
 * 9- reception de la d�cision de a zybo
 * 10- envoie des information sur le UART. Soit juste des valeurs, soit juste 
 *     une alerte de crise 
 */
}
// -----------------------------------------------------------------------------

