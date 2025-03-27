#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 5

// Global variables
int lights[MAX_ROOMS] = {0}; // 0 for OFF, 1 for ON
float temperatures[MAX_ROOMS] = {22.5, 23.0, 21.8, 24.3, 22.1};
int motionDetected[MAX_ROOMS] = {0}; // 0 for NO, 1 for YES

// Function prototypes
void initializeSystem();
void displayMenu();
void controlLights();
void readTemperature();
void detectMotion();
void securitySystem();
void analyzeHouseStatus();

int main() {
    initializeSystem();
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice (1-6) or 0 to Exit: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: controlLights(); break;
            case 2: readTemperature(); break;
            case 3: detectMotion(); break;
            case 4: securitySystem(); break;
            case 5: analyzeHouseStatus(); break;
            case 0: printf("Exiting the system. Goodbye!\n"); break;
            default: printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}

// Initialize default values
void initializeSystem() {
    printf("Initializing Smart Home System...\n");
    srand(time(0)); // Seed for random number generation
}

// Display the main menu
void displayMenu() {
    printf("\n=== Smart Home System ===\n");
    printf("1. Control Lights\n");
    printf("2. Read Temperature\n");
    printf("3. Detect Motion\n");
    printf("4. Security System\n");
    printf("5. Analyze House Status\n");
    printf("0. Exit\n");
}

// Control lights on or off
void controlLights() {
    int room;
    printf("Enter room number (0 to %d): ", MAX_ROOMS - 1);
    scanf("%d", &room);
    if (room < 0 || room >= MAX_ROOMS) {
        printf("Invalid room number.\n");
        return;
    }
    printf("Turn light ON (1) or OFF (0): ");
    scanf("%d", &lights[room]);
    printf("Room %d light is now %s.\n", room, lights[room] ? "ON" : "OFF");
}

// Read temperature for a room
void readTemperature() {
    int room;
    printf("Enter room number (0 to %d): ", MAX_ROOMS - 1);
    scanf("%d", &room);
    if (room < 0 || room >= MAX_ROOMS) {
        printf("Invalid room number.\n");
        return;
    }
    printf("Room %d Temperature: %.2f°C\n", room, temperatures[room]);
}

// Detect motion using random simulation
void detectMotion() {
    int room;
    printf("Enter room number (0 to %d): ", MAX_ROOMS - 1);
    scanf("%d", &room);
    if (room < 0 || room >= MAX_ROOMS) {
        printf("Invalid room number.\n");
        return;
    }
    motionDetected[room] = rand() % 2; // Randomly simulate motion (0 or 1)
    printf("Motion %s in Room %d.\n", motionDetected[room] ? "Detected" : "Not Detected", room);
}

// Simulate a simple security system
void securitySystem() {
    int alert = 0;
    printf("Checking security system...\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (motionDetected[i]) {
            printf("⚠️ Motion detected in Room %d!\n", i);
            alert = 1;
        }
    }
    if (!alert) {
        printf("No motion detected. House is secure.\n");
    }
}

// Display the current status of the house
void analyzeHouseStatus() {
    printf("\n=== House Status ===\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("Room %d -> Light: %s | Temperature: %.2f°C | Motion: %s\n",
               i,
               lights[i] ? "ON" : "OFF",
               temperatures[i],
               motionDetected[i] ? "Detected" : "Not Detected");
    }
}
