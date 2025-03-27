/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

#include <stdio.h>
#include <stdlib.h>

// Global constants
#define MAX_ROOMS 5

// Function prototypes
void initializeSystem(int numRooms, int lights[], int locks[], int motion[], int temps[]);
void displayMenu();
void controlLights(int numRooms, int lights[]);
void readTemperature(int numRooms, int temps[]);
void detectMotion(int numRooms, int motion[]);
void securitySystem(int numRooms, int locks[]);
void analyzeHouseStatus(int numRooms, int lights[], int locks[], int motion[], int temps[]);

int main() {
    int numRooms;

    // Get the number of rooms from the user
    printf("Enter number of rooms (max %d): ", MAX_ROOMS);
    scanf("%d", &numRooms);

    if (numRooms <= 0 || numRooms > MAX_ROOMS) {
        printf("Invalid number of rooms. Exiting program.\n");
        return 1;
    }

    // Arrays to store system states
    int lights[numRooms];  // 0 for OFF, 1 for ON
    int locks[numRooms];   // 1 for Locked, 0 for Unlocked
    int motion[numRooms];  // 1 for Motion Detected, 0 for No Motion
    int temps[numRooms];   // Temperature in each room

    initializeSystem(numRooms, lights, locks, motion, temps);

    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                controlLights(numRooms, lights);
                break;
            case 2:
                readTemperature(numRooms, temps);
                break;
            case 3:
                detectMotion(numRooms, motion);
                break;
            case 4:
                securitySystem(numRooms, locks);
                break;
            case 5:
                analyzeHouseStatus(numRooms, lights, locks, motion, temps);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

void initializeSystem(int numRooms, int lights[], int locks[], int motion[], int temps[]) {
    for (int i = 0; i < numRooms; i++) {
        lights[i] = 0;      // All lights OFF
        locks[i] = 1;       // All doors Locked
        motion[i] = 0;      // No motion detected
        temps[i] = 22;      // Default temperature
    }
    printf("System initialized. All devices are set to default states.\n");
}

void displayMenu() {
    printf("\n===== Smart Home Menu =====\n");
    printf("1. Toggle Light\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Sensor\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
}

void controlLights(int numRooms, int lights[]) {
    int room;
    printf("Enter room number to toggle light (1-%d): ", numRooms);
    scanf("%d", &room);

    if (room < 1 || room > numRooms) {
        printf("Invalid room number.\n");
        return;
    }

    lights[room - 1] = !lights[room - 1];
    printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
}

void readTemperature(int numRooms, int temps[]) {
    int room;
    printf("Enter room number to read temperature (1-%d): ", numRooms);
    scanf("%d", &room);

    if (room < 1 || room > numRooms) {
        printf("Invalid room number.\n");
        return;
    }

    printf("Temperature in Room %d: %d°C\n", room, temps[room - 1]);
}

void detectMotion(int numRooms, int motion[]) {
    int room;
    printf("Enter room number to check motion sensor (1-%d): ", numRooms);
    scanf("%d", &room);

    if (room < 1 || room > numRooms) {
        printf("Invalid room number.\n");
        return;
    }

    printf("Motion in Room %d: %s\n", room, motion[room - 1] ? "Detected" : "No Motion");
}

void securitySystem(int numRooms, int locks[]) {
    int room;
    printf("Enter room number to lock/unlock (1-%d): ", numRooms);
    scanf("%d", &room);

    if (room < 1 || room > numRooms) {
        printf("Invalid room number.\n");
        return;
    }

    locks[room - 1] = !locks[room - 1];
    printf("Room %d is now %s.\n", room, locks[room - 1] ? "Locked" : "Unlocked");
}

void analyzeHouseStatus(int numRooms, int lights[], int locks[], int motion[], int temps[]) {
    printf("\nHouse Status:\n");
    for (int i = 0; i < numRooms; i++) {
        printf("- Room %d: Light %s, Temp %d°C, %s, %s\n", 
            i + 1, 
            lights[i] ? "ON" : "OFF", 
            temps[i], 
            motion[i] ? "Motion Detected" : "No Motion", 
            locks[i] ? "Locked" : "Unlocked");
    }
}

