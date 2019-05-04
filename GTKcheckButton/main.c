#include <gtk/gtk.h>

GtkWidget *txt;

void end_program (GtkWidget *wid, gpointer ptr)
{
    gtk_main_quit ();
}

// callback receives a pointer to referance the calling widget and a second pointer for user to decide how to use
void set_text (GtkWidget *wid, gpointer ptr)
{
    int state = gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (wid)); 
    const char *closed = "closed";
    const char *open = "open";
    if (state)
    {
        gtk_label_set_text (GTK_LABEL (ptr), closed);
    }
    else
    {
        gtk_label_set_text (GTK_LABEL (ptr), open);
    };
}

int main (int argc, char *argv[])
{
    gtk_init (&argc, &argv);

    GtkWidget *win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    GtkWidget *btn = gtk_button_new_with_label ("Close window");
    g_signal_connect (btn, "clicked", G_CALLBACK (end_program), NULL);
    g_signal_connect (win, "delete_event", G_CALLBACK (end_program), NULL);

    GtkWidget *lbl = gtk_label_new ("My label");
    GtkWidget *chk = gtk_check_button_new_with_label ("My check");

    g_signal_connect (chk, "clicked", G_CALLBACK (set_text), lbl);

    GtkObject *adj = gtk_adjustment_new (0, -10, 10, 1, 0, 0);
    txt = gtk_spin_button_new (GTK_ADJUSTMENT (adj), 0, 0);

    GtkWidget *tab = gtk_table_new (2, 2, TRUE);

    gtk_table_attach_defaults (GTK_TABLE (tab), lbl, 0, 1, 0, 1);
    gtk_table_attach_defaults (GTK_TABLE (tab), chk, 1, 2, 0, 1);
    gtk_table_attach_defaults (GTK_TABLE (tab), btn, 0, 1, 1, 2);
    gtk_table_attach_defaults (GTK_TABLE (tab), txt, 1, 2, 1, 2);
    
    // only one item per window, so a table is used to hold the label + 2*button + a entry element.
    gtk_container_add (GTK_CONTAINER (win), tab);
    gtk_widget_show_all (win);
    gtk_main ();
    return 0;
}
