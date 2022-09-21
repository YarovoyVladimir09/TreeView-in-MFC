MFC-based windowed application

The main window should contain a tree (TreeView) in the left part, it should be filled from a text file selected by the user.

Input data format:

"id":"pId":"caption":"status":"message"

где
- id - global identifier
- pId - id of parent node
- caption - caption in the tree
- status - node status 
- message - text

By double-clicking, a MessageBox containing a message from the node should be output

If the node is not active (status = 0), then this is indicated in the name of the node and
the MessageBox is not output when double-clicking 

Example:

-0:(-1):CAP0:1:MESSAGE-0

-1:0:CAP01:1:MESSAGE-01

-2:0:CAP02:0:MESSAGE-02

-3:(-1):CAP1:1:MESSAGE-1

-4:0:CAP11:1:MESSAGE-11

-5:0:CAP12:1:MESSAGE-12

The task was performed according to the C++17 standard, there are two txt files in the TestEx folder to check the operability

![image](https://user-images.githubusercontent.com/94742842/172691627-2f7ebcee-bca7-4428-9f98-45f4db1a34ad.png)


