#include <string>
#define IN_ACCESS 0x00000001        /* File was accessed.  */
#define IN_MODIFY 0x00000002        /* File was modified.  */
#define IN_ATTRIB 0x00000004        /* Metadata changed.  */
#define IN_CLOSE_WRITE 0x00000008   /* Writtable file was closed.  */
#define IN_CLOSE_NOWRITE 0x00000010 /* Unwrittable file closed.  */
#define IN_CLOSE (IN_CLOSE_WRITE | IN_CLOSE_NOWRITE) /* Close.  */
#define IN_OPEN 0x00000020                           /* File was opened.  */
#define IN_MOVED_FROM 0x00000040              /* File was moved from X.  */
#define IN_MOVED_TO 0x00000080                /* File was moved to Y.  */
#define IN_MOVE (IN_MOVED_FROM | IN_MOVED_TO) /* Moves.  */
#define IN_CREATE 0x00000100                  /* Subfile was created.  */
#define IN_DELETE 0x00000200                  /* Subfile was deleted.  */
#define IN_DELETE_SELF 0x00000400             /* Self was deleted.  */
#define IN_MOVE_SELF 0x00000800               /* Self was moved.  */

int getMode(std::string mode) {
  if (mode == "access") {
    return IN_ACCESS;
  } else if (mode == "modify") {
    return IN_MODIFY;
  } else if (mode == "close") {
    return IN_CLOSE;
  } else if (mode == "open") {
    return IN_OPEN;
  } else if (mode == "move") {
    return IN_MOVE;
  } else if (mode == "create") {
    return IN_CREATE;
  } else if (mode == "delete") {
    return IN_DELETE;
  }
  return -1;
}