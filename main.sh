#/bin/bash
END='\033[0m'
RED='\033[0;31m'
BLACK='\033[0;30m'
GREEN='\033[0;32m'

./ft_containers > ft_test
./std_containers > std_test
diff ft_test std_test > diff_output

if [ -s diff_output ]; then
        # The file is not-empty.
        echo "${RED}there was a mistake${END}"
		cat diff_output
else
        # The file is empty.
        echo "${GREEN}Mission succeed${END}"
fi

rm -f ft_test
rm -f std_test
