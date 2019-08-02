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

    // Adiciona um container na janela principal para adicionar o webview
    gtk_container_add(GTK_CONTAINER(mainWindow), GTK_WIDGET(webView));
    
    // Conecta o sinal de destruição da janela ativa para encerrar o programa
    g_signal_connect(mainWindow, "destroy", G_CALLBACK(destroyWindowCallback), NULL);
    
    // Conecta o sinal de fechar o webview para destruir a janela ativa
    g_signal_connect(webView, "close", G_CALLBACK(closeWebViewCallback), mainWindow);
    
    // Carrega a página passada como parametro para o programa
    webkit_web_view_load_uri(webView, argv[1]);
    
    // Leva o foco direto para o webview
    gtk_widget_grab_focus(GTK_WIDGET(webView));
    
    gtk_widget_show_all(mainWindow);
    
    gtk_main();
    
    return 0;
}