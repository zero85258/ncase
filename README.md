# ncase
naming style transfer

# usage

```bash
echo "input_string" | ./ncase --kebab
```

### build

```bash
g++ -o ncase main.cpp
```

### 待完善

```
在這個範例中，我們將程式複製到 /usr/bin/ncase。

執行 dpkg-buildpackage 命令來建置套件。確保你的系統已安裝 dpkg-dev 套件。

dpkg-buildpackage -us -uc
執行完成後，將會在上層目錄中產生一個 .deb 套件檔案。

最後，你可以將該 .deb 套件檔案上傳到自己的套件庫，或使用 dpkg 工具進行安裝。

Copy code
sudo dpkg -i naming-case_1.0_amd64.deb
```
