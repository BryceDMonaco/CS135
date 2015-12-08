/*
    Author: Bryce Monaco
    Created: 11/14/15
    Last Modified: 12/6/15

    This script handles the main menu and is pretty basic. It also applys a 9:16 resolution to the application if it is not on android because
    Unity does not allow 9:16 to be a pre-defined aspect ration outside of mobile builds

    This script contains the string variable required for the project.
*/

using UnityEngine;
using System.Collections;

public class MenuController : MonoBehaviour {
    public string levelName = "TestScene";
	// Use this for initialization
	void Start () {
        if (Application.platform != RuntimePlatform.Android)
        {
            UnityEngine.Screen.SetResolution(331, 589, false);

        }
    }
	
	// Update is called once per frame
	void Update () {
	
	}

    public void StartGame ()
    {
        Application.LoadLevel(levelName);
    }
}
