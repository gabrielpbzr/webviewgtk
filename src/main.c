#include<stdlib.h>
#include <gtk/gtk.h>
int main(int argc, char** argv)
{
    gtk_init(&argc, &argv);
    GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_show_all(win);
    gtk_main();
    
    return 0;
}