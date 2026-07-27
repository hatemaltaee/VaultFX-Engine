# 🏦 VaultFX Engine — Modern C++ Banking & RBAC Security System

<p align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&height=220&color=0:141E30,50:243B55,100:2C5364&text=🏦%20VaultFX%20Engine&fontColor=ffffff&fontSize=45&animation=fadeIn&fontAlignY=38"/>

</p>

<p align="center">

<img src="https://img.shields.io/badge/C%2B%2B-11%2F14%2F17-00599C?style=for-the-badge&logo=cplusplus"/>
<img src="https://img.shields.io/badge/Security-Bitwise%20RBAC-red?style=for-the-badge&logo=security"/>
<img src="https://img.shields.io/badge/Architecture-Modular-success?style=for-the-badge"/>
<img src="https://img.shields.io/badge/File%20Storage-Flat%20Files-orange?style=for-the-badge"/>
<img src="https://img.shields.io/badge/License-MIT-blue?style=for-the-badge"/>

</p>


<h3 align="center">

A Secure, Modular, and Scalable Banking Management System Built with Modern C++

</h3>


<p align="center">

🔐 Security • 🧩 Modular Design • 💾 File Persistence • ⚡ Efficient Permission System

</p>


---

# 📖 Overview

**VaultFX Engine** is a professional console-based banking management system developed using **Modern C++**.

The project is designed around clean architecture principles and focuses on building a realistic banking environment with:

- 🔐 Secure authentication
- 🛡️ Bitwise Role-Based Access Control (RBAC)
- 💳 Client management
- 💰 Transaction processing
- 💾 File-based persistence
- 🧩 Modular and reusable components

The system avoids external dependencies and uses optimized in-memory permission handling combined with safe file operations.

---

# ✨ Key Features

## 💳 Client Management

The system provides complete client record management:

✅ Add new clients  
✅ Update client information  
✅ Search client records  
✅ Delete client records  
✅ Display formatted financial tables  

Additional protections:

- Duplicate account prevention
- Input validation
- Safe record processing


---

## 🔐 Bitwise RBAC Security

A lightweight and efficient permission system built using bitwise operations.

Features:

- 👤 Multi-user authentication
- 🛡️ Role-based authorization
- ⚡ O(1) permission checking
- 🔒 Protected administrative operations
- 🚫 Access denied handling


Example:

```cpp
bool CheckAccessPermission(enPermission Permission)
{
    if (CurrentUser.permission == AllPermission)
        return true;

    return (CurrentUser.permission & Permission) == Permission;
}
