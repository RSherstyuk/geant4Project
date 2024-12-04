#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "QGSP_BERT.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"

#include <iostream> // Для вывода сообщений

int main(int argc, char** argv) {
    std::cout << "Starting Geant4 simulation..." << std::endl;

    // Создаем менеджер запуска
    G4RunManager* runManager = new G4RunManager;

    std::cout << "Initializing detector construction..." << std::endl;
    // Инициализация детекторов и генераторов
    runManager->SetUserInitialization(new DetectorConstruction());
    runManager->SetUserInitialization(new QGSP_BERT);

    std::cout << "Setting user actions..." << std::endl;
    // Пользовательские действия
    runManager->SetUserAction(new PrimaryGeneratorAction());
    runManager->SetUserAction(new RunAction());
    runManager->SetUserAction(new EventAction());

    // Запуск
    std::cout << "Initializing simulation..." << std::endl;
    runManager->Initialize();

    // Обработка команд
    G4UImanager* UImanager = G4UImanager::GetUIpointer();
    UImanager->ApplyCommand("/run/initialize");
    std::cout << "Simulation initialized." << std::endl;

    std::cout << "Starting beam simulation..." << std::endl;
    UImanager->ApplyCommand("/run/beamOn 1000");
    std::cout << "Beam simulation completed." << std::endl;

    // Освобождение ресурсов
    delete runManager;
    std::cout << "Simulation finished." << std::endl;
    

    return 0;
}
