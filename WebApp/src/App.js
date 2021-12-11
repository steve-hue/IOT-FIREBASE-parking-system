import React,{useState,useEffect} from "react";
import './App.css';
import parking from "./parking";
import booking from "./book"
// import { initializeApp } from 'firebase/app';
// import { getDatabase,ref,onValue } from "firebase/database";
import { initializeApp }  from 'firebase/app';
import { getDatabase, ref, set ,onValue,update} from "firebase/database";
import { FaArrowAltCircleLeft } from "react-icons/fa";

function App() {

  const [availability,setAvailability]=useState([])
  const [reserve,setReserve]=useState([])
  // const firebaseConfig = {
  //   apiKey: "AIzaSyCKX6YcW5AtYf7C6P92taOhu42f9zJZvsk",
  //   authDomain: "parking-sparc-iii.firebaseapp.com",
  //   projectId: "parking-sparc-iii",
  //   databaseURL: "https://parking-sparc-iii-default-rtdb.asia-southeast1.firebasedatabase.app/",
  //   storageBucket: "parking-sparc-iii.appspot.com",
  //   messagingSenderId: "133650263687",
  //   appId: "1:133650263687:web:d47c57ee66d0e7b3455222"
  //    };
  // const firebaseConfig = {
  //   apiKey: "AIzaSyC3xO5MZyzlxgrjxE_IWs9zNvZFADS6WGc",
  //   authDomain: "iotpark-9253a.firebaseapp.com",
  //   databaseURL: "https://iotpark-9253a-default-rtdb.asia-southeast1.firebasedatabase.app",
  //   projectId: "iotpark-9253a",
  //   storageBucket: "iotpark-9253a.appspot.com",
  //   messagingSenderId: "87077816106",
  //   appId: "1:87077816106:web:62462599977ec65ef28053",
  //   measurementId: "G-WVGVK6WJNC"
  // };

  const firebaseConfig = {
    apiKey: "AIzaSyD73ljgubmbYjXgHhzzfG8UjWu8y0o91Eo",
    authDomain: "parking-da820.firebaseapp.com",
    databaseURL: "https://parking-da820-default-rtdb.asia-southeast1.firebasedatabase.app/",
    projectId: "parking-da820",
    storageBucket: "parking-da820.appspot.com",
    messagingSenderId: "384605737448",
    appId: "1:384605737448:web:2fccbca86562a36dbad45d",
    measurementId: "G-V7T9BZTR25"
  };

     const app = initializeApp(firebaseConfig);
    
     const database = getDatabase(app);
const fetchData=()=>{
const strr=[]; 
for(let i=1; i<5;i++){

onValue(ref(database, `/parking_data/slot-${i}/status`), (snapshot) => {
  const data = snapshot.val();

 strr.push({name:i,id:data});
  
  
});
}
setAvailability(strr)
console.log(availability);
console.log("ksf")
}


function book(id){
  
const updates={};
setReserve([...reserve,id])
updates[`/book/slot-${id}`]="1"
updates[`/parking_data/slot-${id}/block`]=1

  return update(ref(database),updates)
}

function cancel_book(id){
  
  const updates={};
  setReserve(reserve.filter((item)=>item!==id))
  updates[`/book/slot-${id}`]="0"
  updates[`/parking_data/slot-${id}/block`]=0
  
    return update(ref(database),updates)
  }

  function block(id){
  
    const updates={};
    
    updates[`/parking_data/slot-${id}/block`]=1

    
      return update(ref(database),updates)
    }

    function open(id){
  
      const updates={};
      
      updates[`/parking_data/slot-${id}/block`]="0"
  
      
        return update(ref(database),updates)
      }




// function blockades(id){
  
//   const updates={};
//   updates[`/parking_data/slot-${id}/block`]="1"
//     return update(ref(database),updates)
//   }


useEffect(()=>{
  fetchData()
},[availability])
  
  return (
    <div className="section-container">
    <h1 className="heading">Vellore-SJT Parking System</h1>
    <h4 className="heading"><button />                      Available                  <button className="button"/>                     Occupied </h4>
    <div className="contents">
      {/* <div className="parking">
        {parking.map((item)=>{
          return(
            <div className="items">
              <h3>{item.id}</h3>
              <div><button></button></div>
            </div>
          )
        })}
      </div> */}
      <div className="parking">
        {availability.map((item)=>{
          return(
            <div className="items">
              <h3>P{item.name}</h3>
              <div><button  className={item.id==1 ? "parkkk" : reserve.find((it)=>it===item.name) ? "park" : "parkk"}>{(item.id==0 &&  reserve.find((it)=>it===item.name)) ? "Yet to arrive..." : null}</button></div>
              {item.id==1 ? null :<div>
              <button className="bs-button" onClick={()=>book(item.name)} >Book</button>
              <button className="bs-button" onClick={()=>cancel_book(item.name)}>Cancel</button>
              {reserve.find((it)=>it===item.name) ? <div><button className="bs-button" onClick={()=>block(item.name)}>Block</button>
              <button className="bs-button" onClick={()=>open(item.name)}>Open</button></div>: null}
              </div>}
            </div>
          )
        })}
      </div>
      <div className="details">
     <div className="members"><p>Steve Stagy-19BEE0184</p>
     <p>Mayukh Basak-19BEE0183</p>
     <p>Sanskar Arora-19BEE0166</p></div> 
     <div className="enter">
     <h2>ENTER</h2>
      <FaArrowAltCircleLeft size="30%" />
      </div>
     
      
      </div>
      
      
    </div>
   
    </div>
  );
}

export default App;
