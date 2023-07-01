
FROM ubuntu:latest

# These commands copy your files into the specified directory in the image
# and set that as the working location
WORKDIR /home/koll

COPY myApp /home/koll/

# This command runs your application, comment out this line to compile only
CMD ["./myApp"]

LABEL Name=demo Version=0.0.1
