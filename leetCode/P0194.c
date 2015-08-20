# Read from the file file.txt and print its transposed content to stdout.
awk '{
    for(i=1;i<=NF;i++){
        word[FNR,i]=$i;
    }}END{for(i=1;i<=NF;i++){
            for(j=1;j<=FNR;j++){
                if(j==FNR)
                    print word[j,i]
                else
                    printf word[j,i]" "
            }
    }
}' file.txt