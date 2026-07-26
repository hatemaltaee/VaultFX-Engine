#pragma once

// ===============================
// Navigation Functions
// ===============================

// Pauses and waits for a key press, then returns control back
// to whichever menu loop called the current screen.
// (Prevents recursive MainMenu() calls -> avoids stack growth.)
void GoBackToMainMenu();