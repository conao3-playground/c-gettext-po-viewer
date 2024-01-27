#include <stdio.h>
#include <gettext-po.h>

static void
my_xerror (int severity,
           po_message_t message,
           const char *filename, size_t lineno, size_t column,
           int multiline_p, const char *message_text)
{
  printf ("xerror called:\n  %s\n", message_text);
  if (severity == PO_SEVERITY_FATAL_ERROR)
    abort ();
}


/* Signal a problem that refers to two messages.
   Similar to two calls to xerror.
   If possible, a "..." can be appended to MESSAGE_TEXT1 and prepended to
   MESSAGE_TEXT2.  */
static void
my_xerror2 (int severity,
            po_message_t message1,
            const char *filename1, size_t lineno1, size_t column1,
            int multiline_p1, const char *message_text1,
            po_message_t message2,
            const char *filename2, size_t lineno2, size_t column2,
            int multiline_p2, const char *message_text2)
{
  printf ("xerror2 called:\n  %s\n  %s\n", message_text1, message_text2);
  if (severity == PO_SEVERITY_FATAL_ERROR)
    abort ();
}


int main(int argc, char *argv[]) {
    printf("Hello, world!\n");
    printf("argc = %d, argv[0] = %s, argv[1] = %s\n", argc, argv[0], argv[1]);

    struct po_xerror_handler handler = {
        my_xerror,
        my_xerror2,
    };

    po_file_t file = po_file_read(argv[1], &handler);
    const char * const * domains = po_file_domains(file);
    printf("domains[0] = %s\n", domains[0]);
    printf("domains[1] = %s\n", domains[1]);

    // po_file_write(file, argv[2], &handler);
    printf("header:\n%s\n", po_file_domain_header(file, "messages"));

    po_message_iterator_t iter = po_message_iterator(file, NULL);

    po_file_t write_file = po_file_create();
    po_message_iterator_t write_iter = po_message_iterator(write_file, NULL);
    {
        po_message_t msg = po_next_message(iter);
        printf("msg: %s\n", msg);
        printf("  msgid: %s\n", po_message_msgid(msg));
        printf("  msgstr: %s\n", po_message_msgstr(msg));
    }

    {
        po_message_t msg = po_next_message(iter);
        printf("msg: %s\n", msg);
        printf("  msgid: %s\n", po_message_msgid(msg));
        printf("  msgstr: %s\n", po_message_msgstr(msg));

        po_message_set_fuzzy(msg, 1);
        po_message_insert (write_iter, msg);
    }

    po_message_iterator_free(iter);

    po_file_write(write_file, argv[2], &handler);

    po_file_free(file);
}
