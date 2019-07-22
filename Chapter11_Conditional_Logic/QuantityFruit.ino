// Declare global constants for quantities
const int quantityApples = 1337;
const int quantityBananas = 42;

void setup(){

    // Open serial connection at 9600 Bd
    Serial.begin(9600);
    
}

void loop(){

    Serial.println("#### Comparing number of fruits ####");
    Serial.print("Apples: ");
    Serial.println(quantityApples);
    Serial.print("Bananas: ");
    Serial.println(quantityBananas);
    
    Serial.print("\n");

    // Compare amounts of apples and bananas and print info
    if (quantityApples > quantityBananas) {
        Serial.println("We've got more apples than bananas.");
    }
    else if (quantityApples < quantityBananas) {
        Serial.println("We've got less apples than bananas.");
    }
    else {
        Serial.println("We've got more apples than bananas.");
    }
    
    Serial.print("\n");

    // Add delay
    delay(1000);
}