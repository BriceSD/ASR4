#!/bin/sh
if [ $# = "0" ]
then
  echo 'Erreur, heure non spécifié'

else
  heure=$1
  set `date`
  echo 'Nous sommes le '$3' '$2' '$6', il est :' $heure
fi
