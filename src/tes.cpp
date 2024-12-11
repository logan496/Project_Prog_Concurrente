Table Butler::assignTable(int clientNumber) {
    Table bestFitTable; // Variable pour stocker la meilleure table trouvée
    bool tableFound = false;

    for (Table &emptyTable : dinningRoom.getEmptyTableList()) {
        if (emptyTable.getCapacity() == clientNumber) {
            return emptyTable; // Retourne immédiatement la table si elle correspond exactement
        } else if (emptyTable.getCapacity() >= clientNumber) {
            // Si aucune correspondance exacte, stocke une table avec une capacité suffisante
            if (!tableFound || emptyTable.getCapacity() < bestFitTable.getCapacity()) {
                bestFitTable = emptyTable;
                tableFound = true;
            }
        }
    }

    if (tableFound) {
        return bestFitTable; // Retourne la meilleure correspondance trouvée
    }

    throw std::runtime_error("No suitable table available."); // Gère les cas où aucune table n'est trouvée
}
