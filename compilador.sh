#!/bin/bash

array[1]=$(echo "\\")
array[2]=$(echo "|")
array[3]=$(echo "/")
array[4]=$(echo "-")
SPACE="-"
LIMITE=$(tput cols)
COLUNA=$((LIMITE - 15))
INDICE=0
CONTADOR=0
PORCENTAGEM2=0

clear
while true ; do
INDICE=$(echo "$INDICE + 1" | bc)
tput cup 0 0
echo "$PORCENTAGEM2% - ["
SPACE=$(echo "$SPACE-")
tput cup 0 8
echo  "[31;1m$SPACE>[m\n"
tput cup 0 $COLUNA
echo "] ${array[$INDICE]} - Progresso"
sleep 0.01
CONTADOR=$( expr 1 + $CONTADOR)
if [ $INDICE = 4 ]; then
INDICE=0
fi
TAMANHO2=$( echo $SPACE | wc -c )
TAMANHO=$( echo "$TAMANHO2 - 1 " | bc )
COLUNA2=$( expr $COLUNA - 9 )
[ $TAMANHO -eq $COLUNA2 ] && break
TAMANHO3=$(echo "$TAMANHO + 10" | bc)
PORCENTAGEM=$(echo "$TAMANHO3 * 100" | bc )
PORCENTAGEM2=$(echo "$PORCENTAGEM / $COLUNA" | bc )
done


echo "Script no diretório:"
pwd
gcc main.c -o main
echo "Arquivo compilado com sucesso!!!"


echo "Executando o Editor de Imagens..."


./main