# InMemoryDB
**Overview**:

This C++ program implements an in-memory key-value database that supports basic transaction functionality. It allows setting and getting integer values by string keys within transactions, with the capability to commit or rollback changes made during a transaction.

**Requirements**:

C++17 compatible IDE or compiler 
Standard C++ libraries

**Setup and Running the Program**

1)If Cloning from GitHub:

Clone the Repository or Download the Source Code(ZipFile):

To clone the repository, use the command: git clone [repository URL].
Alternatively, you can download the source code as a ZIP file from the GitHub repository page.
Open the Project in an IDE (such as CLion):

Open your preferred C++ IDE.
Select 'Open Project' and navigate to the cloned repository or unzipped folder.
Important: Ensure that the CMakeLists.txt file is present in the root directory of the project. This file is crucial for the IDE to correctly configure the build settings.
Build and Run the Program Using the IDE's Built-In Tools:
If the IDE prompts you to select a target, choose the executable target defined in your CMakeLists.txt.


2)If Downloading and Opening the Project Directly in an IDE:
Copy the Source Code from the Repository:

Navigate to the repository on GitHub and copy the source code.
Paste it into a New Project File in Your IDE:
Important: Manually create or copy the CMakeLists.txt file into the root directory of the new project.
Use the IDE's Build and Run Commands to Compile and Execute the Program:


**Using the Program**:

After starting the program, input commands directly into the console. Supported commands are:

1) get <key>: Retrieves the value for a specified key.
   
2) put <key> <value>: Sets the value for a specified key.
   
3) begin_transaction: Starts a new transaction.
   
4) commit: Commits the current transaction.
   
5) rollback: Rolls back the current transaction.

**Example of Usage:**

get A

_null_

put A 5

_Error: No transaction in progress_

begin_transaction

put A 5

get A

_null_

put A 6

commit

get A

_6_

commit

_Error: No transaction in progress_

rollback

_Error: No transaction in progress_

get B

_null_

begin_transaction

put B 10

rollback

get B

_null_

**Future Assignment Modifications**:


I feel there are a few things that can be done for this to become an official assignment. Firstly, the instructions should explicitly detail the expected input and output formats, ensuring clarity and reducing potential misunderstandings. I personally went off of the examples included, but it would be useful to specify or explain how it is open to interpretation as long as you follow the instructions. Also, introducing additional database functionalities, such as delete or update operations, could improve the learning experience by mirroring real-world database scenarios more closely. Additionally, if you want to focus more strictly on the coding aspect of this project, developing a grading rubric and focusing on aspects like code efficiency, style, and the handling of cases would provide a more thorough assessment of student work. Finally, incorporating automated testing could improve the grading process's effectiveness and efficiency; I've had this within assignments for other computer science-related classes. It allows for a more consistent and objective evaluation of each function's correctness.











