#include "sc.h"

struct sheet * search_sheet(struct roman *const doc, const char *const name);
struct sheet * new_sheet(struct roman * doc, char * name);
size_t get_num_sheets(const struct roman *const doc);
void free_session(struct session *const session);
void delete_sheet(struct roman * roman, struct sheet * sh, int flg_free);
void delete_doc(struct session * session, struct roman * doc);
