#include <LittleFS.h>

void handleMkdir() {
    String dirName = server.arg("dir"); // Get directory name from POST request
    if (LittleFS.mkdir("/" + dirName)) {
        server.send(200, "text/plain", "Directory created successfully");
    } else {
        server.send(500, "text/plain", "Failed to create directory");
    }
}

// In setup function
server.on("/mkdir", HTTP_POST, handleMkdir);