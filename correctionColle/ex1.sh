if test $# -eq 0
then
  echo "Rép ?"
  read rep
else
  rep=$1
fi
let f=0
let x=0
let d=0

if test -d rep
then
  cd $rep
else
  echo $rep inexistant
  exit 1
fi

for i in *
do
  if test -f $i
  then
    let f+=1
  fi
  if test -x $i
  then
    let x+=1
  fi
  if test -d $i
  then
    let d+=1
  fi
done

echo "$rep contient $f fichiers, $x executables, $d répertoires"
