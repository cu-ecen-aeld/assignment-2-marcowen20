if [ -z $1 ] || [ -z $2 ]
then
	echo "Please specify writefile and writestr"
	exit 1
else
	echo $2 > $1
fi
