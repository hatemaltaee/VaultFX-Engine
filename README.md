# 🏦 VaultFX Engine — Modern C++ Banking & RBAC Security System

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-11%2F14%2F17-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" alt="C++ Standard" />
  <img src="https://img.shields.io/badge/Security-Bitwise%20RBAC-ff69b4?style=for-the-badge&logo=shield" alt="RBAC Security" />
  <img src="https://img.shields.io/badge/Architecture-Modular-brightgreen?style=for-the-badge" alt="Architecture" />
  <img src="https://img.shields.io/badge/License-MIT-blue?style=for-the-badge" alt="License" />
</p>

---

## 📌 Overview

**VaultFX Engine** is a high-performance, modular console banking application engineered in Modern C++. Built with clean architecture principles, it incorporates a memory-efficient **Bitwise Role-Based Access Control (RBAC)** security model, zero-dependency flat-file persistence layers, and defensive stream buffer recovery.

---

## 🔥 Key Features

<table>
  <tr>
    <td width="50%">
      <h3>💳 Client Management</h3>
      <ul>
        <li><b>CRUD Records:</b> Safe addition, modification, search, and soft deletion of accounts.</li>
        <li><b>Formatted Visual Tables:</b> Clean, aligned CLI tables for financial visibility.</li>
        <li><b>Input Validation:</b> Guard clauses preventing duplicate account creation.</li>
      </ul>
    </td>
    <td width="50%">
      <h3>🔒 Bitwise RBAC Security</h3>
      <ul>
        <li><b>Multi-User Authentication:</b> Isolated state management per active session.</li>
        <li><b>Bitwise Permission Masks:</b> O(1) evaluation for active permission vectors.</li>
        <li><b>Access Control Feedback:</b> Custom redirection and warning protocols.</li>
      </ul>
    </td>
  </tr>
  <tr>
    <td width="50%">
      <h3>📊 Transactions Subsystem</h3>
      <ul>
        <li><b>Deposits & Withdrawals:</b> Atomic balance updates with range validation.</li>
        <li><b>Liquidity Dashboard:</b> Aggregate totals and real-time bank statistics.</li>
      </ul>
    </td>
    <td width="50%">
      <h3>💾 File Persistence & I/O Safety</h3>
      <ul>
        <li><b>Flat-File Serialization:</b> Custom delimited record parsing.</li>
        <li><b>Buffer Recovery:</b> Explicit stream clearing via <code>cin.fail()</code> & <code>cin.ignore()</code>.</li>
      </ul>
    </td>
  </tr>
</table>

---

## 🏗️ System Architecture & File Structure

```text
📁 VaultFX-Engine/
├── 📄 Main.cpp                # Application entry point & control loop
├── 📁 Business Logic/
│   ├── ClientServices.cpp     # Client operations logic
│   └── UserServices.cpp       # User management & permission validation
├── 📁 Data & Persistence/
│   ├── ClientFileManager.cpp  # Flat-file IO for client records
│   └── UserFileManager.cpp    # Flat-file IO for user authentication
├── 📁 Core Utilities/
│   ├── ReadData.cpp           # Type-safe input validation & stream cleaning
│   ├── StringUtils.cpp        # Delimited string splitting algorithms
│   ├── UI.cpp                 # Screen formatting, menus, & header rendering
│   └── Navigation.cpp         # Flow routing & menu traversals
└── 📁 Entities/
    ├── Client.h               # Client data structures
    └── User.h                 # User structures & bitwise permission masks
```

---

## 🔑 Security & Permission Logic

Permissions are mask-evaluated using a memory-efficient bitwise matrix:

| Permission Flag | Bitwise Mask | Binary Vector | Description |
| :--- | :---: | :---: | :--- |
| **`ShowClients`** | `1` | `0000 0001` | Grant permission to view client directories |
| **`AddClient`** | `2` | `0000 0010` | Grant permission to create new client records |
| **`DeleteClient`** | `4` | `0000 0100` | Grant permission to remove client records |
| **`UpdateClient`** | `8` | `0000 1000` | Grant permission to modify client details |
| **`FindClient`** | `16` | `0001 0000` | Grant permission to search accounts |
| **`Transaction`** | `32` | `0010 0000` | Grant permission to execute financial transactions |
| **`ManageUser`** | `64` | `0100 0000` | Administrative control over user accounts |
| **`AllPermission`** | `-1` | `1111 1111` | Full administrative root access |

> 💡 **Bitwise Access Evaluation (C++ Example)**
```cpp
bool CheckAccessPermission(enPermission Permission) {
    if (CurrentUser.permission == AllPermission)
        return true;

    return (CurrentUser.permission & Permission) == Permission;
}
```

---

## 🚀 Quick Start & Installation

### Prerequisites
* A C++11 (or higher) compliant compiler (`g++`, `clang++`, or `MSVC`).

### Compilation & Execution

```bash
# 1️⃣ Clone the repository
git clone https://github.com/your-username/VaultFX-Engine.git

# 2️⃣ Navigate to project directory
cd VaultFX-Engine

# 3️⃣ Compile source files
g++ -std=c++11 *.cpp -o VaultFX

# 4️⃣ Launch executable
./VaultFX
```

---

## 📜 License

Distributed under the **MIT License**. Free for educational and commercial modification.
