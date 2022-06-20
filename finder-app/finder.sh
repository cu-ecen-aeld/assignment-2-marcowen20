if [ -z $1 ] || [ -z $2 ] || [ ! -d $1 ]
then
	echo "Please specify filesdir and searchstr"
	exit 1
else
	echo "The number of files are $(grep -r -c $2 $1 | wc -l) and the number of matching lines are $(grep -r -o $2 $1 | wc -l)"
fi
