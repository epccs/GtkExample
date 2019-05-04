// sudo apt-get install libgtk2.0-dev
// there is long list of flags and lib's so use the pkg-config command 
// gcc `pkg-config gtk+-2.0 --cflags` gtktest.c -o gtktest `pkg-config gtk+-2.0 --libs`
// for Makefile:
// LDLIBS = -lcurl -lpthread `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0`

#include <gtk/gtk.h>

void end_program (GtkWidget *wid, gpointer ptr)
{
    gtk_main_quit ();
}

int main (int argc, char *argv[])
{
    gtk_init (&argc, &argv);
    GtkWidget *win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    GtkWidget *btn = gtk_button_new_with_label ("Close window");
    g_signal_connect (btn, "clicked", G_CALLBACK (end_program), NULL);
    g_signal_connect (win, "delete_event", G_CALLBACK (end_program), NULL);
    GtkWidget *lbl = gtk_label_new ("My label");
    GtkWidget *box = gtk_vbox_new (FALSE, 5);
    gtk_box_pack_start (GTK_BOX (box), lbl, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX (box), btn, TRUE, TRUE, 0);
    
    // only one item per window, so a vbox is used to hold the lbl and btn
    gtk_container_add (GTK_CONTAINER (win), box);
    gtk_widget_show_all (win);
    gtk_main ();
    return 0;
}