#include <string>
#include <vector>
#include <iostream>

#include "ahFunctions.h"

class sheet {
private:
    int BASE_MOD = 5;

    int baseHPSP = 10;

    int level;

    std::string name;
    std::string race;
    std::string background;

    // For backgrounds, we can make a seperate .cpp do like background.cpp then inheritence onto a new .cpp then use getSkill()
    // to get the value of a variable.
    // We could to save space in online-ide to make only one CPP, do int getSkill(background,skill) to make it simple.
    // Use a vector or an array and a for-each loop

    int maxAbility = 10;

    int strength;
    int perception;
    int endurance;
    int charisma;
    int intelligence;
    int agility;
    int luck;

    int strMod;
    int perMod;
    int endMod;
    int chaMod;
    int intMod;
    int agiMod;
    int lckMod;

    int sp;
    int hp;
    int dt;
    int ac;
    int healingRate;
    int passiveSense;
    int combatsequence;
    int partyNerve;
    int fatigue;

    int barter;
    int breach;
    int crafting;
    int energyWeapons;
    int explosives;
    int guns;
    int intimidation;
    int medicine;
    int meleeWeapons;
    int science;
    int sneak;
    int speech;
    int survival;
    int unarmed;

public:

    std::string input;

    sheet() {
    }

    std::string getName() {return this->name;}
    void setName(std::string name) {this->name = name;}

    std::string getRace() {return this->race;}
    void setRace(std::string race) {this->race = race;}

    int getStrength(){return this->strength;}
    int getPerception(){return this->perception;}
    int getEndurance(){return this->endurance;}
    int getCharisma(){return this->charisma;}
    int getIntelligence(){return this->intelligence;}
    int getAgility(){return this->agility;}
    int getLuck(){return this->luck;}

    void setStrength(int s) {this->strength = s;}
    void setPerception(int p) {this->perception = p;}
    void setEndurance(int e){this->endurance = e;}
    void setCharisma(int c) {this->charisma = c;}
    void setIntelligence(int i) {this->intelligence = i;}
    void setAgility(int a) {this->agility = a;}
    void setLuck(int l) {this->luck = l;}

    int getStrMod() {return this->strMod;}
    int getPerMod() {return this->perMod;}
    int getEndMod() {return this->endMod;}
    int getChaMod() {return this->chaMod;}
    int getIntMod() {return this->intMod;}
    int getAgiMod() {return this->agiMod;}
    int getLckMod() {return this->lckMod;}

    int getBarter() {return this->barter;}
    int getBreach() {return this->breach;}
    int getCrafting() {return this->crafting;}
    int getEnergyWeapons() {return this->energyWeapons;}
    int getExplosives() {return this->explosives;}
    int getGuns() {return this->guns;}
    int getIntimidation() {return this->intimidation;}
    int getMedicine() {return this->medicine;}
    int getMeleeWeapons() {return this->meleeWeapons;}
    int getScience() {return this->science;}
    int getSneak() {return this->sneak;}
    int getSpeech() {return this->speech;}
    int getSurvival() {return this->survival;}
    int getUnarmed() {return this->unarmed;}

    void setBarter(int skillBarter) {this->barter = skillBarter;}
    void setBreach(int skillBreach) {this->breach = skillBreach;}
    void setCrafting(int skillCrafting) {this->crafting = skillCrafting;}
    void setEnergyWeapons(int skillEnergyWeapons) {this->energyWeapons = skillEnergyWeapons;}
    void setExplosives(int skillExplosives) {this->explosives = skillExplosives;}
    void setGuns(int skillGuns) {this->guns = skillGuns;}
    void setIntimidation(int skillIntimidation) {this->intimidation = skillIntimidation;}
    void setMedicine(int skillMedicine) {this->medicine = skillMedicine;}
    void setMeleeWeapons(int skillMeleeWeapons) {this->meleeWeapons = skillMeleeWeapons;}
    void setScience(int skillScience) {this->science = skillScience;}
    void setSneak(int skillSneak) {this->sneak = skillSneak;}
    void setSpeech(int skillSpeech) {this->speech = skillSpeech;}
    void setSurvival(int skillSurvival) {this->survival = skillSurvival;}
    void setUnarmed(int skillUnarmed) {this->unarmed = skillUnarmed;}

    // The output is a string that adds a + sign so modifier gets displayed as a positive. Negatives just get displayed.
    std::string getStrWithSymbol(int mod) {
        if (mod >= 0) {
            return "+"+std::to_string(mod);
        } else {
            return std::to_string(mod);
        }
    }

    // Auto Calculator Base that is based on levels.
    // As soon as level is change, auto-calculate
    // As soon as special changes, auto-calculate
    // or have a 'save' button that auto-calcuales everything.

    // int calcBase(int level) {

    // }

    // TODO: Incorporate Levels into this 1-20. ex: calStaminaPoints(int level, int agiMod){}
    // then have if-then statements to set the base.
    int calcModifier(int abilityScore) {
        return abilityScore - BASE_MOD;
    }

    int calcStaminaPoints(int agiMod) {
        return this->baseHPSP + agiMod;
    }

    int calcHP(int endMod) {
        return this->baseHPSP + endMod;
    }

    void setAbilitiesToDefault() {
        int baseAbility = 5;
        this->strength = baseAbility;
        this->perception = baseAbility;
        this->endurance = baseAbility;
        this->charisma = baseAbility;
        this->intelligence = baseAbility;
        this->agility = baseAbility;
        this->luck = baseAbility;
    }

    void calcAllAbilityModifiers() {
        this->strMod = calcModifier(getStrength());
        this->perMod = calcModifier(getPerception());
        this->endMod = calcModifier(getEndurance());
        this->chaMod = calcModifier(getCharisma());
        this->intMod = calcModifier(getIntelligence());
        this->agiMod = calcModifier(getAgility());
        this->lckMod = calcModifier(getLuck());
    }

    void setupName() {
        displayDialog(" What is your character's name?");
        std::cout << "======================================" << std::endl;
        setName(getInput(1));
        std::cout << "======================================" << std::endl;
    }

    bool confirmationSelectedRace(std::string selectedRace) {
        std::string input;

        std::cout << "  Are you sure you would want to select \"" << selectedRace << "\" as your race?" << std::endl;
        std::cout << "======================================" << std::endl;
        std::cout << "  - (Y)es" << std::endl;
        std::cout << "  - (N)o" << std::endl;
        std::cout << "======================================" << std::endl;
        input = getInput();
        std::cout << "======================================" << std::endl;

        if (input == "y" || input == "yes") {
            setRace(selectedRace);
            return true;
        } else {
            return false;
        }

    }

    void setupRace() {
        std::string input;
        std::string selectedRace;
        bool isUnknownCommand = false;
        bool isConfirmation = false;

        while (true) {
            displayDialog(" Please select a race:");
            std::cout << "======================================" << std::endl;
            displayDialog(" - (H)uman");
            displayDialog(" - (G)houl");
            displayDialog(" - (S)ynth, Gen 2");
            displayDialog(" - (R)obot");
            displayDialog(" - (Super) Mutant");
            std::cout << "======================================" << std::endl;

            if (isUnknownCommand == true && input != "") {
                std::cout << "  UNKNOWN COMMAND" << std::endl;
                std::cout << "======================================" << std::endl;
                isUnknownCommand = false;
            }

            input = getInput();
            std::cout << "======================================" << std::endl;

            if (input == "h" || input == "human") {
                displayDialog(" Please select a variant:");
                std::cout << "======================================" << std::endl;
                std::cout << "  - (H)uman" << std::endl;
                std::cout << "  - (V)ariant Human" << std::endl;
                std::cout << "  - (S)ynth, Gen 3" << std::endl;
                std::cout << "  - (B)ack" << std::endl;
                std::cout << "======================================" << std::endl;
                input = getInput();
                std::cout << "======================================" << std::endl;

                // TODO: This
                if (input == "h" || input == "human") {
                    selectedRace = "Human";
                    isConfirmation = confirmationSelectedRace(selectedRace);
                    if (isConfirmation == true) {
                        break;
                    }
                } else if (input == "v" || input == "variant human") {
                    std::cout << "WORK IN PROGRESS" << std::endl;
                    // selectedRace = "Variant Human";
                    // isConfirmation = confirmationSelectedRace(selectedRace);
                    // if (isConfirmation == true) {
                    //     break;
                    // }
                } else if (input == "s" || input == "synth" || input == "synth, gen 3") {
                    std::cout << "WORK IN PROGRESS" << std::endl;
                    // selectedRace = "Synth, Gen 3";
                    // isConfirmation = confirmationSelectedRace(selectedRace);
                    // if (isConfirmation == true) {
                    //     break;
                    // }
                } else if (input == "b" || input == "back") {
                }

            } else if (input == "g" || input == "ghoul") {
                std::cout << "WORK IN PROGRESS" << std::endl;
            } else if (input == "s" || input == "synth, gen 2" || input == "synth") {
                std::cout << "WORK IN PROGRESS" << std::endl;
            } else if (input == "r" || input == "Robot") {
                std::cout << "WORK IN PROGRESS" << std::endl;
            } else if (input == "super" || input == "sup" || input == "super mutant") {
                std::cout << "WORK IN PROGRESS" << std::endl;
            } else if (input != "") {
                isUnknownCommand = true;
            }
        }
    }

    void setupAbilityScores() {

        std::string input;

        int inputInt;
        int inputLength = input.length();
        bool isUnknownCommand = false;
        bool isAbilityScoreNotZero = false;

        int maxAbilityScore = 38;
        int freeAbilityPoints;
        int totalCurrentAbilityScores;

        setAbilitiesToDefault();

        displayDialog(" Please assign your ability scores.");
        std::cout << "======================================" << std::endl;

        while(true) {

            calcAllAbilityModifiers();

            totalCurrentAbilityScores = getStrength() + getPerception() + getEndurance() + getCharisma() + getIntelligence() + getAgility() + getLuck();
            freeAbilityPoints = maxAbilityScore - totalCurrentAbilityScores;

            // Better way, capture last digit. If it equals 0 set to 10. If it is any other set it to that. Beginning doesn't matter. Just need letter.

            std::cout << "  Strength:        " << getStrength()     << "    " << "(" << getStrWithSymbol(getStrMod()) << ")" << std::endl;
            std::cout << "  Perception:      " << getPerception()   << "    " << "(" << getStrWithSymbol(getPerMod()) << ")" << std::endl;
            std::cout << "  Endurance:       " << getEndurance()    << "    " << "(" << getStrWithSymbol(getEndMod()) << ")" << std::endl;
            std::cout << "  Charisma:        " << getCharisma()     << "    " << "(" << getStrWithSymbol(getChaMod()) << ")" << std::endl;
            std::cout << "  Intelligence:    " << getIntelligence() << "    " << "(" << getStrWithSymbol(getIntMod()) << ")" << std::endl;
            std::cout << "  Agility:         " << getAgility()      << "    " << "(" << getStrWithSymbol(getAgiMod()) << ")" << std::endl;
            std::cout << "  Luck:            " << getLuck()         << "    " << "(" << getStrWithSymbol(getLckMod()) << ")" << std::endl;
            std::cout << "======================================" << std::endl;
            std::cout << "To spend your points, please type the initial letter of the ability followed by the number." << std::endl;
            std::cout << "Example: A2 will set Agility to 2." << std::endl;
            std::cout << "After filling your ability scores, type (D)one." << std::endl;
            std::cout << "======================================" << std::endl;
            std::cout << "You currently have " << freeAbilityPoints << " ability points to spend." << std::endl;
            std::cout << "======================================" << std::endl;

            if (isUnknownCommand == true && (input != "" || input != "d" || input != "done") ) {
                std::cout << "UNKNOWN COMMAND" << std::endl;
                std::cout << "======================================" << std::endl;
                isUnknownCommand = false;
            }

            if (isAbilityScoreNotZero == true) {
                std::cout << "ABILITY SCORES IS NOT 0" << std::endl;
                isAbilityScoreNotZero = false;
            }

            // std::cout << x << std::endl;
            input = getInput();
            inputLength = input.length();
            std::cout << "======================================" << std::endl;

            if ((input == "done" || input == "d") && freeAbilityPoints == 0) {
                std::cout << "COMPLETED SETUP" << std::endl;
                std::cout << "======================================" << std::endl;
                break;
            } else if (input == "done" || input == "d") {
                isAbilityScoreNotZero = true;
            }

            if (inputLength == 2 && (input[1]-'0' >= 1 && input[1]-'0' <= 9) ) {
                inputInt = input[1] - '0';
            } else if (inputLength == 3 && input[1] == '1' && input[2] == '0') {
                inputInt = 10;
            } else if (input != "d" || input != "done" || input != "") {
                isUnknownCommand = true;
            }

            if (isUnknownCommand == false) {
                if (input[0] == 's') {
                    setStrength(inputInt);
                } else if (input[0] == 'p') {
                    setPerception(inputInt);
                } else if (input[0] == 'e') {
                    setEndurance(inputInt);
                } else if (input[0] == 'c') {
                    setCharisma(inputInt);
                } else if (input[0] == 'i') {
                    setIntelligence(inputInt);
                } else if (input[0] == 'a') {
                    setAgility(inputInt);
                } else if (input[0] == 'l') {
                    setLuck(inputInt);
                } else {
                    isUnknownCommand = true;
                }
            }
        }
    }

    void setupSkills() {
        int halfLuck = getLckMod() / 2;

        setBarter(getChaMod() + halfLuck);
        setCrafting(getIntMod() + halfLuck);
        setEnergyWeapons(getPerMod() + halfLuck);
        setExplosives(getPerMod() + halfLuck);
        setGuns(getAgiMod() + halfLuck);
        setMeleeWeapons(getStrMod() + halfLuck);
        setScience(getIntMod() + halfLuck);
        setSneak(getAgiMod() + halfLuck);
        setSpeech(getChaMod() + halfLuck);
        setSurvival(getEndMod() + halfLuck);
        setUnarmed(getStrMod() + halfLuck);

        if (getPerMod() >= getIntMod()) {
            setBreach(getPerMod() + halfLuck);
            setMedicine(getPerMod() + halfLuck);
        } else if (getIntMod() > getPerMod()) {
            setBreach(getIntMod() + halfLuck);
            setMedicine(getIntMod() + halfLuck);
        }

        if (getStrMod() >= getChaMod()) {
            setIntimidation(getStrMod() + halfLuck);
        } else if (getChaMod() > getStrMod()) {
            setIntimidation(getChaMod() + halfLuck);
        }

    }

    void setupCharacter() {

        setupName();
        setupRace();
        setupAbilityScores();
        setupSkills();

    }

    void calcAllVariables () {

    }

    void displayInputOptions() {
        std::cout << "  - (C)haracter Info" << std::endl;
        std::cout << "  - (S)PECIAL " << std::endl;
        std::cout << "  - (Sk)ills" << std::endl;
        std::cout << "  - (L)evel Up" << std::endl;
        std::cout << "  - (E)xit" << std::endl;
        std::cout << "======================================" << std::endl;
    }

    void displayCharacterInfo() {
        std::cout << "======================================" << std::endl;
        std::cout << "  Race: " << getRace() << std::endl;
        std::cout << "  Background: " << "BACKGROUND_HERE" << std::endl;
        std::cout << "  Level: " << "LEVEL_HERE" << std::endl;
        std::cout << "======================================" << std::endl;
    }

    void displayAbilityScores() {
        std::cout << "======================================" << std::endl;
        std::cout << "  Strength:        " << getStrength()     << "    " << "(" << getStrWithSymbol(getStrMod()) << ")" << std::endl;
        std::cout << "  Perception:      " << getPerception()   << "    " << "(" << getStrWithSymbol(getPerMod()) << ")" << std::endl;
        std::cout << "  Endurance:       " << getEndurance()    << "    " << "(" << getStrWithSymbol(getEndMod()) << ")" << std::endl;
        std::cout << "  Charisma:        " << getCharisma()     << "    " << "(" << getStrWithSymbol(getChaMod()) << ")" << std::endl;
        std::cout << "  Intelligence:    " << getIntelligence() << "    " << "(" << getStrWithSymbol(getIntMod()) << ")" << std::endl;
        std::cout << "  Agility:         " << getAgility()      << "    " << "(" << getStrWithSymbol(getAgiMod()) << ")" << std::endl;
        std::cout << "  Luck:            " << getLuck()         << "    " << "(" << getStrWithSymbol(getLckMod()) << ")" << std::endl;
        std::cout << "======================================" << std::endl;
    }

    void displaySkills() {
        std::cout << "======================================" << std::endl;
        std::cout << "(CHA)         Barter              " << "(" << getStrWithSymbol(getBarter()) << ")" << std::endl;
        std::cout << "(PER/INT)     Breach              " << "(" <<getStrWithSymbol(getBreach()) << ")" << std::endl;
        std::cout << "(INT)         Crafting            " << "(" <<getStrWithSymbol(getCrafting()) << ")" << std::endl;
        std::cout << "(PER)         Energy Weapons      " << "(" <<getStrWithSymbol(getEnergyWeapons()) << ")" << std::endl;
        std::cout << "(PER)         Explosives          " << "(" <<getStrWithSymbol(getExplosives()) << ")" << std::endl;
        std::cout << "(AGI)         Guns                " << "(" <<getStrWithSymbol(getGuns()) << ")" << std::endl;
        std::cout << "(STR/CHA)     Intimidation        " << "(" <<getStrWithSymbol(getIntimidation()) << ")" << std::endl;
        std::cout << "(PER/INT)     Medicine            " << "(" <<getStrWithSymbol(getMedicine()) << ")" << std::endl;
        std::cout << "(STR)         Melee Weapons       " << "(" <<getStrWithSymbol(getMeleeWeapons()) << ")" << std::endl;
        std::cout << "(INT)         Science             " << "(" <<getStrWithSymbol(getScience()) << ")" << std::endl;
        std::cout << "(AGI)         Sneak               " << "(" <<getStrWithSymbol(getSneak()) << ")" << std::endl;
        std::cout << "(CHA)         Speech              " << "(" <<getStrWithSymbol(getSpeech()) << ")" << std::endl;
        std::cout << "(END)         Survival            " << "(" <<getStrWithSymbol(getSurvival()) << ")" << std::endl;
        std::cout << "(STR)         Unarmed             " << "(" <<getStrWithSymbol(getUnarmed()) << ")" << std::endl;
        std::cout << "======================================" << std::endl;
    }

    void displaySheet() {

        // TODO: Display only name, race, background, and level.
        // Add other options to view ability scores, skills, inventory, etc.

        std::string input;

        bool isUnknownCommand = false;

        while(true) {

            std::cout << getName() << std::endl;

            if (input == "" || input == "c" || input == "character" || input == "character info") {
                displayCharacterInfo();
            } else if (input == "s" || input == "special") {
                displayAbilityScores();
            } else if (input == "sk" || input == "skills" || input == "skill") {
                displaySkills();
            }
            displayInputOptions();

            if (input == "l" || input == "level up") {
                std::cout << "======================================" << std::endl;
                std::cout << "  LEVELING UP IS WIP" << std::endl;
                std::cout << "======================================" << std::endl;
            }

            if (isUnknownCommand == true && input != "") {
                std::cout << "UNKNOWN COMMAND" << std::endl;
                isUnknownCommand = false;
            }


            input = getInput();
            std::cout << "======================================" << std::endl;

            if (input == "l" || input == "level up") {
                // Execute levelUp();
            } else if (input == "e" || input == "exit") {
                exit(0);
            } else if (input != "s" || input != "special" || input != "" || input != "c" || input != "character" || input != "character info" || input != "sk" || input != "skills" || input != "skill") {
                isUnknownCommand = true;
            }
        }




    }

};