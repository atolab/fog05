Remove everything:

```
pip3 uninstall -y fog05 yaks papero

```


Install zenoh API

```
### ubuntu 18.04
curl -L -o /tmp/lib18.tar.gz https://www.dropbox.com/s/1i2v5kxl8vw575t/lib18.tar.gz
tar -xzvf /tmp/lib18.tar.gz -C /tmp

### ubuntu 16.04
curl -L -o /tmp/lib16.tar.gz https://www.dropbox.com/s/hpxdymyx26det6p/lib16.tar.gz
tar -xzvf /tmp/lib16.tar.gz -C /tmp

###
sudo cp /tmp/libzenohc.so /usr/local/lib
git clone https://github.com/atolab/zenoh-python
cd zenoh-python
git checkout 1ced877917816acea13e58c151e02cf950ad8009
sudo python3 setup.py install
cd ..

```

Install YAKS API


```
git clone https://github.com/atolab/yaks-python
cd yaks-python
git checkout 50c9fc7d022636433709340f220e7b58cd74cefc
sudo make install
cd ..

```



Clone fog05 from and switch to branch 5gcoral

```
git clone https://github.com/atolab/fog05
cd fog05
git checkout 5gcoral

```

Make and install the python types and API


```
sudo pip3 install pyang pyangbind
sudo make -C src/im/python
sudo make -C src/im/python install
sudo make -C src/api/python/api install

```

Copy all the plugins needed plugins in the /etc/fos/plugins directory
You need to copy all the files except for the configuration ones for each plugins

Update the configuration files of agent `/etc/fos/agent.json` and the one of the plugins `/etc/fos/plugins/<name>/<name>_plugin.json` by replacing the port of the `ylocator` with 7447


Download and install the agent

```
#### ubuntu 18
curl -L -o /tmp/agent.tar.gz https://www.dropbox.com/s/0xga125gtkxp7ot/agent18.tar.gz
#### ubuntu 16
curl -L -o /tmp/agent.tar.gz https://www.dropbox.com/s/h31qs0k6klk53qe/agent16.tar.gz

tar -xzvf /tmp/agent.tar.gz
sudo cp agent /etc/fos/agent

```


Download and install yaks


```
### only ubuntu 18
curl -L -o /tmp/yaks.tar.gz https://www.dropbox.com/s/q1lcd20ug8ddhhs/yaks.tar.gz
tar -xzvf /tmp/yaks.tar.gz
sudo cp zenoh /etc/fos/zenoh
sudo mv /etc/fos/zenoh /etc/fos/zenohd
sudo cp yaks-plugin.cmxs /etc/fos/yaks-plugin.cmxs
sudo cp yaksd /etc/fos/yaksd
```


Update your descriptor following: https://github.com/atolab/fog05_demo/blob/master/fim_api/fdu_lxd_net.json

Example of start.py script https://github.com/atolab/fog05_demo/blob/master/fim_api/yaks/start.py




##### Commits ID used for this build

```
ocaml - ocaml-variants.4.07.1+flambda
apero-core c36dee532259feb5d5bda31feb1461cd854c1e88
apero-net 824c954ed464577a23c18842fedcfe8dd860094f
apero-time b0446b79b8265d4944b58414e7adc26a035dd954
zenoh ff2d124ff7894059b6eee10cedaa1560757c087e
yaks-common 5d2e70dcac6fe97acc5a8a5868f1dbe110343e61
yaks-ocaml d07664597b9f62445e0cf83abd32dea9956baf06
yaks 87cca6e109e72179267d5a64ebeb3489de5d60a8
zenoh-c 58bad2cf1616f405fe401b22a713b95a6fef786c
zenoh-python 1ced877917816acea13e58c151e02cf950ad8009
yaks-python 50c9fc7d022636433709340f220e7b58cd74cefc
```