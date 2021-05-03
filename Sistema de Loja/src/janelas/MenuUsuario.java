package janelas;

import sistema.Sistema;

public class MenuUsuario extends javax.swing.JFrame {

    public MenuUsuario() {
        initComponents();
        lblTitulo.setText("Bem vindo, " + Sistema.getUsuarioNome());
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        lblTitulo = new javax.swing.JLabel();
        btnCriarNovaLoja = new javax.swing.JButton();
        btnAbrirLoja = new javax.swing.JButton();
        btnDeletarLoja = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);
        setTitle("Sistema de Loja");
        setResizable(false);
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosed(java.awt.event.WindowEvent evt) {
                formWindowClosed(evt);
            }
        });

        lblTitulo.setFont(new java.awt.Font("Consolas", 1, 24)); // NOI18N
        lblTitulo.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblTitulo.setText("Bem vindo, Fulano");

        btnCriarNovaLoja.setFont(new java.awt.Font("Consolas", 1, 12)); // NOI18N
        btnCriarNovaLoja.setText("Criar Nova Loja");
        btnCriarNovaLoja.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnCriarNovaLojaActionPerformed(evt);
            }
        });

        btnAbrirLoja.setFont(new java.awt.Font("Consolas", 1, 12)); // NOI18N
        btnAbrirLoja.setText("Abrir Loja");
        btnAbrirLoja.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnAbrirLojaActionPerformed(evt);
            }
        });

        btnDeletarLoja.setFont(new java.awt.Font("Consolas", 1, 12)); // NOI18N
        btnDeletarLoja.setText("Deletar Loja");
        btnDeletarLoja.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnDeletarLojaActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(lblTitulo, javax.swing.GroupLayout.DEFAULT_SIZE, 380, Short.MAX_VALUE)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(0, 0, Short.MAX_VALUE)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                            .addComponent(btnCriarNovaLoja, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(btnAbrirLoja, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(btnDeletarLoja, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addGap(0, 0, Short.MAX_VALUE)))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(lblTitulo)
                .addGap(18, 18, 18)
                .addComponent(btnCriarNovaLoja)
                .addGap(18, 18, 18)
                .addComponent(btnAbrirLoja)
                .addGap(18, 18, 18)
                .addComponent(btnDeletarLoja)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void btnCriarNovaLojaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnCriarNovaLojaActionPerformed
        // Evento 1
    }//GEN-LAST:event_btnCriarNovaLojaActionPerformed

    private void btnAbrirLojaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnAbrirLojaActionPerformed
        // Evento 2
    }//GEN-LAST:event_btnAbrirLojaActionPerformed

    private void btnDeletarLojaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnDeletarLojaActionPerformed
        // Evento 3
    }//GEN-LAST:event_btnDeletarLojaActionPerformed

    private void formWindowClosed(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowClosed
        Sistema.resetarUsuario();
        new Login().setVisible(true);
    }//GEN-LAST:event_formWindowClosed

    public static void main(String args[]) {
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(MenuUsuario.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(MenuUsuario.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(MenuUsuario.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(MenuUsuario.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }

        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new MenuUsuario().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnAbrirLoja;
    private javax.swing.JButton btnCriarNovaLoja;
    private javax.swing.JButton btnDeletarLoja;
    private javax.swing.JLabel lblTitulo;
    // End of variables declaration//GEN-END:variables
}
