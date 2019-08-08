#include<stdlib.h>
#include <gtk/gtk.h>
#include <webkit2/webkit2.h>

void destroyWindowCallback(GtkWidget* widget, GtkWidget* window)
{
    gtk_main_quit();
}

static gboolean closeWebViewCallback(WebKitWebView* webView, GtkWidget* window)
{
    gtk_widget_destroy(window);
    
    return TRUE;
}

int main(int argc, char** argv)
{
    gtk_init(&argc, &argv);
    
    GtkWidget *mainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_default_size(GTK_WINDOW(mainWindow), 800, 600);
    
    WebKitWebView* webView = WEBKIT_WEB_VIEW(webkit_web_view_new());

    // Add a container to the main window to hold the webView
    gtk_container_add(GTK_CONTAINER(mainWindow), GTK_WIDGET(webView));
    
    // Connect the closing signal of window to event of destroying the app
    g_signal_connect(mainWindow, "destroy", G_CALLBACK(destroyWindowCallback), NULL);
    
    // Connect the closing signal of webView widget to call window closing event
    g_signal_connect(webView, "close", G_CALLBACK(closeWebViewCallback), mainWindow);
    
    // Load URI provided as an argument to the program
    webkit_web_view_load_uri(webView, argv[1]);
    
    // Focus on webView
    gtk_widget_grab_focus(GTK_WIDGET(webView));
    
    //Display all widgets of mainWindow
    gtk_widget_show_all(mainWindow);
    
    gtk_main();
    
    return 0;
}