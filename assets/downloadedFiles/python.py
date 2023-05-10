# fireBase Cloud Imports
try:
    from firebase_admin import firestore
    from firebase_admin import credentials
    import firebase_admin
    import pyrebase

except:
    print("Error with Firebase_Admin")

# fireBase Cloud Credentials
credPath = {
    "type": "service_account",
    "project_id": "project---ru",
    "private_key_id": "226ae805ac0bfda6b161a83f8c1d94c37bc799d9",
    "private_key": "-----BEGIN PRIVATE KEY-----\nMIIEvQIBADANBgkqhkiG9w0BAQEFAASCBKcwggSjAgEAAoIBAQCy7z9lZri81SgE\nPCIWol8iNTZ5YRKRxP+U5N6E40tX1OJMShQJ1d+wdn1KP4sSTtXxZIere2h4rY7Z\naxO0gqmA3gxRBb1OLfv9KKUJCyKm12qYjM/QAD5N9kX5yTWhAnNjOMZHMH1Sp34+\njZqvuozzStKKVuNaTu+X2xFczVt4N0Ab99rGjW9fdnC+UftpRkDXsJagO7CHPPHg\norzVeLGo/wR4tMZTcThW/JR6OIwd/yNs3eb58CYCvraGkRJoflkojKLCKiUe0fKp\n7QCgYA0sr440t3tWTQoO+Nf4WVSMd1I92GcB12OgOl4izf8ABHqhdniXu5Q2t6+3\ngFVytrfJAgMBAAECggEAGovqMOYThFhvbmlpeUgvqwiQA2QGeD/s1y85YCfElsxL\nopve6zKi1DBQGELjJB00GnMaubM+ZaECL3l2W/KCqU7ILwEV+9JQr1dnXLcdNfmB\npA5ICojutWxTJ2LVpQSTD+ZtbERiY2/cB/XEPEwF+1ZfdAy+ADjzzOjAY69H4ca4\n7AQ5GGU8/FQu1YUudii9bmVBHP7gVQ6Em9GEXeG0y0mDCXNXIXG4F9MZmqxqfuXK\nY27aSIsaxbPv93b2yN7PhOqxZdh5lyFZd48+zD5987Ck7lleqmedBF2p/MTJ9FXc\nt0KLGf6OJ3xqrxuc0xgtV/IFs5KD+K/pEE1RgDfebQKBgQDpJCxp0x6IN5zamGki\nkk7wzeweznvCytwWWMjZTyCyJ+XStuqIXfo30dO2rRdEcO1jnzUBtDRYeRA7nAiC\nNY4nRqVmPfd3cxYoy9CljXaOJBmzZePRUkFET6nQHtsM2Gzm8zblbGm7//XsWmX9\nyI8juVDBVoLfM2tbrxLt/Fs9kwKBgQDEen1YcseEdVvpkTN9uzWr2E2NKnQXcXmx\n5SiwA53idpW/9nBP5RDNxOyWWXb6O7bM21g64op0E2r6/2oX+9C4lyYTgekhDmrc\n4TmmoEr9ETSoJoWY6F3UcIou7+6HfvcyhbUBtuAoN6VbtH5Vc6xorQdDGbjI8Fga\noSCbUSTuswKBgQCohIAh4ftAxMn464+a8JxkzMOupNuqOk2JTZWoFdzxSYuCmrq9\n5Qf3DxD0Cvs1elbs2mhLGgF4LdHA9JDl5WYiF5t4YrQcQDC1PlVLRQx7w7ZcCPr6\nE3WfteFt0M/O4iUdbpGwlYN745DTzafJIA3u6YVoqmqggR9Jvyt0oCMnRwKBgFL4\nEtR169EAqiaQvXi7xKdjuSQCqHF55tT7m1nwvQxz3Trp+3WRmq36GZpH/1kePEx3\n1+NN5P+tb4C8uPWVzgcVNOwJ8QOXjgLmTS0TBXeme2ECm2n9vhnGyGOXyFeJgyPf\nmJc3vaLeFMMMDklRhp3Ra36nbwPTkrD0F8ve0UTHAoGALwdQYGgzjAmOHmYPannJ\nbjVnZLUhGGjToTVwL3u2JP93h9/yi9b0O3iXxLmAZqAhC94Ll8TnxoL5CU7PnGuX\nn7X5iw+o6/THXsS1BGvzRLtaM6sg00UbtRc+hyq38l1xra1dX3SpAlt0Run+YCGF\nuuAuGAUX36QN6n0RK+HdUvE=\n-----END PRIVATE KEY-----\n",
    "client_email": "firebase-adminsdk-fp6ik@project---ru.iam.gserviceaccount.com",
    "client_id": "110657935735128997860",
    "auth_uri": "https://accounts.google.com/o/oauth2/auth",
    "token_uri": "https://oauth2.googleapis.com/token",
    "auth_provider_x509_cert_url": "https://www.googleapis.com/oauth2/v1/certs",
    "client_x509_cert_url": "https://www.googleapis.com/robot/v1/metadata/x509/firebase-adminsdk-fp6ik%40project---ru.iam.gserviceaccount.com"
};
try:
    login = credentials.Certificate(credPath)
    firebase_admin.initialize_app(login)
    db = firestore.client()
except:
    print("Error with Firebase LogIn")

# fireBase RealTime DataBase Credentials
config = {
    "apiKey": "AIzaSyAUEYQvNrTXX8uepftMjpSS_dGSXku15Fw",
    "authDomain": "project---ru.firebaseapp.com",
    "databaseURL": "https://project---ru-default-rtdb.asia-southeast1.firebasedatabase.app",
    "projectId": "project---ru",
    "storageBucket": "project---ru.appspot.com",
    "messagingSenderId": "777439668308",
    "appId": "1:777439668308:web:2d7e27d226c35e77cba5c1",
    "measurementId": "G-84JSMEP0CC"
};
try:
    firebase = pyrebase.initialize_app(config)
    dbRT = firebase.database()
except:
    print("Error with pyrebase logIn")


db.collection("sensors").document("temp").update({
                "key": "data",
                "key1": 1
            })
db.collection("remainderList").document("docId").delete()

collection = db.collection("AlarmList").stream()
for x in collection:
    print(x.to_dict())
    # print(x.to_dict()["key"])

# get data from real time datadase
mode = db.child("key").get().val()
print(mode)