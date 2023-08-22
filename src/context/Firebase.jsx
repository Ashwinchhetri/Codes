import { createContext, useContext, useState, useEffect } from "react";
import { initializeApp } from "firebase/app";
import { getAuth, createUserWithEmailAndPassword, signInWithEmailAndPassword, GoogleAuthProvider, signInWithPopup, onAuthStateChanged } from 'firebase/auth'

const FirebaseContext = createContext(null);

const firebaseConfig = {
    apiKey: "AIzaSyAAdEiLb6M4iVcaD5HRbKaAuXrA0DRsXdY",
    authDomain: "bookify-31856.firebaseapp.com",
    projectId: "bookify-31856",
    storageBucket: "bookify-31856.appspot.com",
    messagingSenderId: "999541591165",
    appId: "1:999541591165:web:1b9e92ae7e8e033e22f514"
};

export const useFirebase = () => useContext(FirebaseContext)

const firebaseApp = initializeApp(firebaseConfig);
const firebaseAuth = getAuth(firebaseApp);

const googleProvider = new GoogleAuthProvider();


export const FirebaseProvider = (props) => {

    const [user, setUser] = useState(null);

    useEffect(() => {
        onAuthStateChanged(firebaseAuth, (user) => {
            if(user) setUser(user);
            else setUser(null);
        })
    }, [])


    const signupUserWithEmailAndPassword = (email, password) => createUserWithEmailAndPassword(firebaseAuth, email, password);

    const signinUserWithEmailAndPassword = (email, password) => signInWithEmailAndPassword(firebaseAuth, email, password);

    const signinWithGoogle = () => signInWithPopup(firebaseAuth, googleProvider);

    const isLoggedIn = user ? true : false;

    return(
        <FirebaseContext.Provider value={{ signupUserWithEmailAndPassword, signinUserWithEmailAndPassword, signinWithGoogle, isLoggedIn }}>{props.children}</FirebaseContext.Provider>
    )
};