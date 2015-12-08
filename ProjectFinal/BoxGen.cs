/*
    Author: Bryce Monaco
    Created: 11/14/15
    Last Modified: 12/6/15

    This script handles the random generation of each matrix, most functions are called by the GameManager script.

    This script contains the 2D array required for the project, see line 19 (the boxGrid GameObject Array)
    It also has loops and decisions, as well as user input (see Update function)
*/

using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class BoxGen : MonoBehaviour {
    public int[] boxSeed = new int[9]; //0 is hidden, 1 is shown
    public GameObject gameManager;
    public GameObject[,] boxGrid = new GameObject[3, 3];
    public Color[] boxColor;
    public int maxProbability = 3;
    public bool isTarget = false; //To check if the player is looking for this one
    public Transform[] respawnPoints;
    public Vector3 moveDirection;

    private bool hasStoredBoxes = false;
    private bool hasFoundRespawn = false;

    public Color mainColor;

	// Use this for initialization
	void Start () {

        Time.timeScale = 1.0f;

        gameManager = GameObject.Find("_GameManager");

        /*
        //This block finds all gameobjects that are respawn points, then stores their transform component
        GameObject[] rPointGO; //Stands for Respawn Point GameObject
        rPointGO = GameObject.FindGameObjectsWithTag("Respawn");

        respawnPoints = new Transform[rPointGO.Length];

        for (int i = 0; i < rPointGO.Length; i++)
        {
            respawnPoints[i] = rPointGO[i].transform;
        }

        Debug.Log("Number of Respawn Points Found: " + respawnPoints.Length);
        */

        Color thisBoxColor = boxColor[Random.Range(0, boxColor.Length)];
        int onBoxNum = 0;

	    for (int i = 0; i < 3; i++)
        {
            for (int ii = 0; ii < 3; ii++)
            {
                boxGrid[i, ii] = transform.Find(i + "-" + ii + "Box").gameObject;

                boxGrid[i, ii].GetComponent<SpriteRenderer>().color = thisBoxColor;

                int randomInt = (int) Random.Range(1, maxProbability);

                if (randomInt == (int) Random.Range(1, maxProbability))
                {
                    boxGrid[i, ii].SetActive(false);

                    boxSeed[onBoxNum] = 0; //This box is hidden
                } else
                {
                    boxSeed[onBoxNum] = 1; //This box is shown
                }

                onBoxNum++;

            }
        }

        transform.GetComponent<Rigidbody2D>().mass = 0;

    }

    // Update is called once per frame
    void Update () {
        if (isTarget)
        {
            mainColor = transform.FindChild("0-0Box").GetComponent<SpriteRenderer>().color;

            gameManager.GetComponent<GameManager>().ApplyModelColor(mainColor);

        }

        if (Input.GetMouseButtonDown(0))
        {
            //Debug.Log("BOP");
            Vector3 wp = Camera.main.ScreenToWorldPoint(Input.mousePosition);
            Vector2 touchPos = new Vector2(wp.x, wp.y);
            if (GetComponent<BoxCollider2D>() == Physics2D.OverlapPoint(touchPos))
            {
                CheckIfTarget();

            }
        }
    }

    void FixedUpdate ()
    {
        //ForceRegeneration();

        

    }

    public void ForceRegeneration ()
    {
        Color thisBoxColor = boxColor[Random.Range(0, boxColor.Length)];

        if (!hasStoredBoxes)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int ii = 0; ii < 3; ii++)
                {
                    boxGrid[i, ii] = transform.FindChild(i + "-" + ii + "Box").gameObject;

                }
            }

            hasStoredBoxes = true;
        }

        int onBoxNum = 0;

        for (int i = 0; i < 3; i++)
        {
            for (int ii = 0; ii < 3; ii++)
            {
                boxGrid[i, ii].SetActive(true);

                boxGrid[i, ii].GetComponent<SpriteRenderer>().color = thisBoxColor;

                int randomInt = (int)Random.Range(1, maxProbability);

                if (randomInt == (int)Random.Range(1, maxProbability))
                {
                    boxGrid[i, ii].SetActive(false);

                    boxSeed[onBoxNum] = 0; //This box is hidden

                } else
                {
                    boxSeed[onBoxNum] = 1; //This box is shown
                }

                onBoxNum++;
            }
        }
    }

    void OnTriggerEnter2D (Collider2D target)
    {
        if (target.CompareTag("Barrier"))
        {
            if (isTarget)
            {
                RespawnBox(false);
            } else
            {
                RespawnBox(true);
            }
        }
    }

    public void RespawnBox (bool doRegen)
    {
        if (!hasFoundRespawn)
        {
            //This block finds all gameobjects that are respawn points, then stores their transform component
            GameObject[] rPointGO; //Stands for Respawn Point GameObject
            rPointGO = GameObject.FindGameObjectsWithTag("Respawn");

            respawnPoints = new Transform[rPointGO.Length];

            for (int i = 0; i < rPointGO.Length; i++)
            {
                respawnPoints[i] = rPointGO[i].transform;
            }

            //Debug.Log("Number of Respawn Points Found: " + respawnPoints.Length);
        }

        switch (doRegen)
        {
            case false: //This box does not need to be regenerated, likely the target
                transform.position = respawnPoints[Random.Range(0, (respawnPoints.Length - 1))].position;

                gameManager = GameObject.Find("_GameManager");

                gameManager.GetComponent<GameManager>().CheckTargetSeed(boxSeed);

                break;

            case true: //The box needs to be regenerated, likely a dummy
                ForceRegeneration();

                int point = Random.Range(0, (respawnPoints.Length - 1));

                //Debug.Log("Going to point " + point + " - Length: " + respawnPoints.Length);

                transform.position = respawnPoints[point].position;

                break;

        }

        transform.GetComponent<Rigidbody2D>().gravityScale = Random.Range(0.01f, 1.0f);
        transform.GetComponent<Rigidbody2D>().velocity = new Vector2(0, 0);

    }

    public void CheckIfTarget ()
    {
        if (isTarget)
        {
            gameManager.GetComponent<GameManager>().UpdateGameScore(1);
            ForceRegeneration();
            RespawnBox(false);

        } else
        {
            Debug.Log("nah");
        }
    }
}
