if test $# -eq 0
then
  echo Nom du fichier de notes
  read fichier
  else
  fichier=$1
fi
while read ligne
do
  set $ligne
  nom=$1
  prenom=$2
  let som=0
  let nb=0

  while test $# -gt 2
  do
    let som+=$3
    let nb+=1
    shift
  done

  let moy=`echo $som / $nb | bc`
  echo $nom $prenom a $som points
  if [ $moy -ge 10 ]
  then
    echo $nb notes et une moyenne de `echo $som / $nb | bc -l`
  else
    echo $nb notes et une moyenne de `echo $som / $nb | bc -l`*
  fi
done<$fichier
