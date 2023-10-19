#!/bin/bash

clear
echo "This bash file will automatically start 3 terminal and run the supplied jar for you,"
echo "then please setup the jar accordingly"
echo ""
echo ""
echo "How to setup:"
echo ""
echo "You will need at least 1 master, and 2 clients"
echo "Then you can create two account on each clients, using the /register command"
echo "To access help command on master, type 'help'"
echo "To access help command on client, type '/help'"
echo "Further explaination about each commands is available on the EF-RPC documentation file."
echo "You may run the jar file manually to add more clients."

echo ""
echo ""
read -p "Press enter to continue..."

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
gnome-terminal -- bash -c "java -jar '${DIR}/OOPUsingJavaProject.jar'; exec bash"
gnome-terminal -- bash -c "java -jar '${DIR}/OOPUsingJavaProject.jar'; exec bash"
gnome-terminal -- bash -c "java -jar '${DIR}/OOPUsingJavaProject.jar'; exec bash"
