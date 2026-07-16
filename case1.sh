echo "Enter a number:"
read num
case $num in 
1) echo "One";;
2) echo "Two";;
3) echo "Three";;
4) echo "Four";;
*) echo "Sorry, it is bigger than Four";;
esac
