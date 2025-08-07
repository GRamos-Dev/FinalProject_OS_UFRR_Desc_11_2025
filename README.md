# Driver Android para Ativação Automática da Lanterna com Temporizador

Universidade Federal de Roraima  
Departamento de Ciência da Computação  
Disciplina: Sistemas Operacionais – DCC403

## Autores

**Lucas Nobre**  
**Guilherme Ramos**  
**Kauã Victor**

---

## Descrição

Este projeto consiste no desenvolvimento e teste de um **driver nativo para Android** capaz de ativar automaticamente a lanterna (flash LED) do smartphone **30 segundos após a inicialização do sistema**, sem depender de aplicativos (APK) ou interface gráfica.  
A solução é implementada a nível de sistema, modificando ou estendendo a HAL (Hardware Abstraction Layer) do Android para controlar o hardware diretamente durante o boot.

---

## Objetivos

- Ativar o flash do LED do dispositivo 30 segundos após o boot do Android.
- Implementar o controle via módulo nativo (C/C++) ou modificação da HAL da câmera.
- Integrar o driver ao processo de inicialização do Android através do init.rc ou serviço nativo.
- Validar o funcionamento no **Android Emulator** e, opcionalmente, em dispositivos reais.

---

## Ferramentas e Tecnologias Utilizadas

- **Android Studio** (AVD Manager, Emulator)
- **Android NDK**
- **AOSP (Android Open Source Project)** – (para modificação de HAL)
- **ADB e Fastboot**
- **Linguagens**: C/C++, Shell Script, (Java opcional)
- **QEMU com Android** (opcional)

---

## Estrutura do Projeto

```
/driver_flashlight/
│
├── src/
│   ├── flashlight_driver.c / flashlight_driver.cpp   # Módulo nativo do driver (C ou C++)
│   ├── Android.mk / CMakeLists.txt                  # Build script do módulo
│   └── scripts/
│        └── init.flashlight.rc                      # Script de inicialização
│
├── README.md                                        # Este arquivo
└── docs/
     └── arquitetura.pdf                             # Documentação e estudos (opcional)
```

---

## Etapas do Desenvolvimento

### 1. **Configuração do Ambiente**
- Instale o Android Studio com o NDK e SDK.
- Baixe uma imagem Android compatível com suporte a câmera/flash no emulador.
- (Opcional) Clone e compile o AOSP para modificar HAL.

### 2. **Implementação do Driver**
- Crie ou modifique o módulo do kernel/HAL responsável pelo controle do flash LED.
- Implemente a lógica de temporizador (`sleep(30)` ou `alarm()`).
- Garanta que a ativação do hardware seja feita por chamada nativa (C/C++).

### 3. **Integração com o Sistema**
- Configure o arquivo `init.rc` ou crie um serviço nativo personalizado para acionar o driver após o boot.
- Inicie o driver via script de inicialização ou serviço nativo do Android.

### 4. **Emulação e Testes**
- Utilize o Android Emulator para testar a funcionalidade (certifique-se de habilitar suporte a flash).
- Monitore os logs com **logcat** para depuração.
- Valide a ativação automática da lanterna sem interação do usuário.
- Teste persistência após reinicializações.
- (Opcional) Valide em dispositivo físico via ADB.

---

## Execução e Testes

1. **Build do driver:**  
   Compile o módulo nativo usando o NDK (`ndk-build` ou `cmake`).

2. **Deploy do driver:**  
   Copie o módulo para o dispositivo/emulador via ADB.

3. **Configuração do serviço:**  
   Edite `init.rc` ou adicione um serviço customizado para acionar o driver no boot.

4. **Testes:**
   - Reinicie o emulador/dispositivo.
   - Aguarde 30 segundos após o boot.
   - Verifique se o flash LED é ativado automaticamente.
   - Use `logcat` para inspecionar logs de debug.
   - Repita os testes para garantir persistência.

---

## Referências

- [Android HAL Documentation](https://source.android.com/docs/core/architecture/hidl/hal)
- [NDK Guides](https://developer.android.com/ndk/guides)
- [Kernel GPIO Interface](https://docs.kernel.org/driver-api/gpio/index.html)
- [Init.rc Scripting](https://android.googlesource.com/platform/system/core/+/master/init/README.md)

---

## Observações

- O controle do flash LED pode variar conforme o hardware e versão do Android.
- Emuladores normalmente não possuem flash físico, utilize recursos avançados de simulação.
- O desenvolvimento e teste de drivers requer permissões administrativas/root.

---
