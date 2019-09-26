Remove everything:

```
pip3 uninstall -y fog05 yaks papero

```


Install zenoh API

```
curl -L -o libzenohc.so https://www.dropbox.com/s/sewvuvq187vt14s/libzenohc.so
sudo cp libzenohc.so /usr/local/lib
git clone https://github.com/atolab/zenoh-python
cd zenoh-python
sudo python3 setup.py install
cd ..

```

Install YAKS API


```
git clone https://github.com/atolab/yaks-python
cd yaks-python
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
curl -L -o /tmp/agent.tar.gz https://www.dropbox.com/s/tot5io70kx5jf21/fos_new.tar.gz
tar -xzvf /tmp/agent.tar.gz
sudo cp agent /etc/fos/agent

```


Download and install yaks


```

curl -L -o /tmp/yaks.tar.gz https://www.dropbox.com/s/v55js274504z5f5/yaks.tar.gz
tar -xzvf /tmp/yaks.tar.gz
sudo cp zenoh /etc/fos/zenoh
sudo mv /etc/fos/zenoh /etc/fos/zenohd
sudo cp yaks-plugin.cmxs /etc/fos/yaks-plugin.cmxs
sudo cp yaksd /etc/fos/yaksd
```


Update your descriptor following: https://github.com/atolab/fog05_demo/blob/master/fim_api/fdu_lxd_net.json

Example of start.py script https://github.com/atolab/fog05_demo/blob/master/fim_api/yaks/start.py





