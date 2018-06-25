# Carriera Universitaria in Flex e Bison
Parser in Flex/Bison per il parsing di un file di input formattato in una determinata maniera.

### Prerequisiti
  Assicurarsi di avere installato sul proprio PC [**GCC**](https://gcc.gnu.org/install/binaries.html), [**Flex**](https://github.com/westes/flex/releases) e [**Bison**](https://www.gnu.org/software/bison/).

### Come creare l'eseguibile

Per compilare il tutto ed avere accesso all'eseguibile .exe sarà necessario:
  1. Avviare il prompt dei comandi
  2. Utilizzare il comando cd per spostarsi nella cartella contenente tutti i file
  3. Eseguire il comando *make*
  
Verranno creati una serie di file, quello da utilizzare è semplicemente l'eseguibile **carriera_universitaria.exe**.

### Come utilizzare l'eseguibile

Per poter avviare la procedura di parsing, bisognera utilizzare uno dei seguenti comandi:

  1. *carriera_universitaria.exe* <*nome_del_file.txt*
  2. *carriera_universitaria.exe* <*nome_del_file.txt* >*nome_del_file_di_output.txt*
Il primo comando stamperà a video il risultato, il secondo creerà un file .txt dove verrà inserito il risultato.


Un esempio di file da poter utilizzare per il parsing è il file di testo *progetto.txt*.
Tutti i dettagli sono presenti nella documentazione.
 
